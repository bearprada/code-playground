#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

#include "SEMUN.H"

#define TEXT_SZ 1024


static int set_semvalue(void);
static void del_semvalue(void);
static int semaphore_p(void);
static int semaphore_v(void);

static int sem_id;

int main()
{
   int *shared_sort,*end_sort,*flag;
   void *shared_memory=(void *)0;
   void *p1_memory=(void *)0;
   int shmid,p1id;
   int i;
 //  printf("s1 enter ok");
   shmid=shmget((key_t)5555,sizeof(int)*TEXT_SZ,0666 | IPC_CREAT);
   p1id= shmget((key_t)5588,sizeof(int)*2,0666 | IPC_CREAT);
   
   shared_memory=shmat(shmid,(void *)0,0);
   p1_memory    =shmat(p1id,(void *)0,0);
   
   shared_sort=(int *)shared_memory;
   flag=       (int *)p1_memory;
   
   flag[0]=0;
   printf("s1 set 0 start\n");
   for(i=0;i<TEXT_SZ;i++)
   {
      shared_sort[i]=0;
   }
   printf("s1 set 0 end\n");
   
   srand((unsigned int)getpid());
   sem_id = semget((key_t)1111, 1, 0666 | IPC_CREAT);
   if (!set_semvalue()) {
            fprintf(stderr, "Failed to initialize semaphore\n");
            exit(EXIT_FAILURE);
        }
   
   for(i=0;i<TEXT_SZ;i++)
   {
      if (!semaphore_p()) exit(EXIT_FAILURE);
      shared_sort[i]++;
      if (!semaphore_v()) exit(EXIT_FAILURE);
   }
   flag[0]=1;
   
   printf("s1 flag[0]=%d\n",flag[0]);
   
  /* for(i=0;i<=TEXT_SZ;i++)
   {
      shared_sort[i]=rand()%100000;
   }*/
   
   del_semvalue();
   
   shmdt(shared_memory);
   shmdt(p1_memory);
   
   shmctl(shmid,IPC_RMID,0);
   shmctl(p1id,IPC_RMID,0);
   
   exit(EXIT_SUCCESS);
}






static int set_semvalue(void)
{
    union semun sem_union;

    sem_union.val = 1;
    if (semctl(sem_id, 0, SETVAL, sem_union) == -1) return(0);
    return(1);
}

/* The del_semvalue function has almost the same form, except the call to semctl uses
 the command IPC_RMID to remove the semaphore's ID. */

static void del_semvalue(void)
{
    union semun sem_union;
    
    if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
        fprintf(stderr, "Failed to delete semaphore\n");
}

/* semaphore_p changes the semaphore by -1 (waiting). */

static int semaphore_p(void)
{
    struct sembuf sem_b;
    
    sem_b.sem_num = 0;
    sem_b.sem_op = -1; /* P() */
    sem_b.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_b, 1) == -1) {
        fprintf(stderr, "semaphore_p failed\n");
        return(0);
    }
    return(1);
}

/* semaphore_v is similar except for setting the sem_op part of the sembuf structure to 1,
 so that the semaphore becomes available. */

static int semaphore_v(void)
{
    struct sembuf sem_b;
    
    sem_b.sem_num = 0;
    sem_b.sem_op = 1; /* V() */
    sem_b.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_b, 1) == -1) {
        fprintf(stderr, "semaphore_v failed\n");
        return(0);
    }
    return(1);
}
