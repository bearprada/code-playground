#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <semaphore.h>
#define limit 1000000

double partial_sum=0;
pthread_mutex_t work_mutex;

void *computing(void *arg);

int main() {
	int i,j;

    pthread_t t1,t2,t3,t4;

	pthread_mutex_init(&work_mutex, NULL);
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
	printf("%.0f\n",partial_sum);
    return 0;
}

void *computing(void *arg) {
	int s=(int)arg , end , start , i ;
	start = s *(limit/4)+1;
	end = start + (limit/4) -1;
	printf ("%d %d \n",start,end);

	for(i=start ; i<=end ; i++){
		    pthread_mutex_lock(&work_mutex);
		    partial_sum+=i;
			pthread_mutex_unlock(&work_mutex);
	}
    printf ("i finish ,I'm NO.%d\n",arg);
	pthread_exit(0);
}
