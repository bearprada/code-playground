
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "shm_com.h"

int main()
{
    int temp,i,j,k;
	int B[1024];
    void *shared_memory = (void *)0;
    struct shared_use_st *shared_stuff;
    int shmid;

    srand((unsigned int)getpid());    

    shmid = shmget((key_t)123, sizeof(struct shared_use_st), 0666 | IPC_CREAT);

    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }

    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1) {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n", (int)shared_memory);

    shared_stuff = (struct shared_use_st *)shared_memory;
    shared_stuff->flag1 = 1;
	shared_stuff->flag2 = 1;
	
	//亂數初始
	for(i=0;i<1024;i++){
		k = rand()%10240;
		shared_stuff->some_text[i] = k;
	}
	shared_stuff->flag1 = 2;
	
	//前半部排序
    for(i=0;i<512;i++){
		for(j=i+1;j<512;j++){
			if(shared_stuff->some_text[j] <shared_stuff->some_text[i]){
					temp = shared_stuff->some_text[j];
					shared_stuff->some_text[j] = shared_stuff->some_text[i];
					shared_stuff->some_text[i] = temp;
			}
		}
	}
	//等待p2
	while(shared_stuff->flag2 == 1){
		sleep(1);
		printf("waiting for process2...\n");
	}
	//合併排序
	k=0;
	i=0;
	j=512;
	while(i!=512 && j!=1024){
		if(shared_stuff->some_text[i] < shared_stuff->some_text[j]){
			B[k++] = shared_stuff->some_text[i++];
		}else{
			B[k++] = shared_stuff->some_text[j++];
		}
	}
	//合併餘值
	while(i<512){
		B[k++]=shared_stuff->some_text[i++];
	}
	while(j<1024){
		B[k++]=shared_stuff->some_text[j++];
	}
	
	for(i=0;i<1024;i++)
		printf("%d ",B[i]);
/* Lastly, the shared memory is detached and then deleted. */
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

