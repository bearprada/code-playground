#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

#include "semun.h"
#include "shm_com.h"

static int set_semvalue(void);
static int semaphore_p(void);
static int semaphore_v(void);
static int sem_id;

int main()
{
   void *shared_memory=(void *)0;
   struct shared_use_st *shared_stuff;
   int shm_id;
   int i,j;
   
   //set semaphone
   sem_id = semget((key_t)1000, 1, 0666 | IPC_CREAT);
   if (!set_semvalue()) {
            fprintf(stderr, "Failed to initialize semaphore\n");
            exit(EXIT_FAILURE);
    }   
    //set share memory
   shm_id=shmget((key_t)1000,sizeof(struct shared_use_st),0666 | IPC_CREAT);
	//requist memory
   shared_memory = shmat(shm_id, (void *)0, 0);
    if (shared_memory == (void *)-1) {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n", (int)shared_memory);
    //bind&init memory structure
    shared_stuff = (struct shared_use_st *)shared_memory;
	
	while(shared_stuff->flag1 == 1){
		sleep(1);
		printf("waiting for process1...\n");
	}
	//compete
    for(j=0;j<100;j++){
      if (!semaphore_p()) exit(EXIT_FAILURE);   
	  for(i=0;i<1024;i++)
	      shared_stuff->some_text[i]++;
      if (!semaphore_v()) exit(EXIT_FAILURE);
   }
   
   shared_stuff->flag2 = 2;
   
   printf ("hello");
   //terminal prosedure
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
   
   exit(EXIT_SUCCESS);
}


static int set_semvalue(void)
{
    union semun sem_union;

    sem_union.val = 1;
    if (semctl(sem_id, 0, SETVAL, sem_union) == -1) return(0);
    return(1);
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



