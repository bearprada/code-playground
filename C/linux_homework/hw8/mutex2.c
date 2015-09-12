#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 10240*10240

void *computing(void *arg);

int A[SIZE] , B[SIZE], C[SIZE];

int main() {
	int i,j;
	for(i=0;i<SIZE;i++)
		    A[i] = B[i] = 1;
    pthread_t t1,t2,t3,t4;

    pthread_create(&t1, NULL, computing, (void *)0);
    pthread_create(&t2, NULL, computing, (void *)1);
    pthread_create(&t3, NULL, computing, (void *)2);
    pthread_create(&t4, NULL, computing, (void *)3);
    printf("\nWaiting for thread to finish...\n");
    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);
    pthread_join(t4, 0);
    printf("Thread joined\n");
	for(i=0;i<SIZE;i++)
		printf ("%d ",C[i]);
    return 0;
}

void *computing(void *arg) {
	int s=(int)arg , end , start , i ;
	start = s *(SIZE/4);
	end = start + (SIZE/4) -1;
	printf ("%d %d \n",start,end);
	for(i=start ; i<=end ; i++)
		    C[i] = A[i] + B[i];
	pthread_exit(0);
}
