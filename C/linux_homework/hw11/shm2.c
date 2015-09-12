
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
    int temp,i,j;
    void *shared_memory = (void *)0;
    struct shared_use_st *shared_stuff;
    char buffer[BUFSIZ];
    int shmid;

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
	
	printf ("%d ",shared_stuff->flag1);
	while(shared_stuff->flag1 == 1){
		sleep(1);
		printf("waiting for process1...\n");
	}
	//sortting
	for(i=512;i<1024;i++){
		for(j=i+1;j<1024;j++){
			if(shared_stuff->some_text[j] <shared_stuff->some_text[i]){
					temp = shared_stuff->some_text[j];
					shared_stuff->some_text[j] = shared_stuff->some_text[i];
					shared_stuff->some_text[i] = temp;
			}
		}
	}
	shared_stuff->flag2 = 2;
	//umount share memory
	if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
	
	exit(EXIT_SUCCESS); 
}
