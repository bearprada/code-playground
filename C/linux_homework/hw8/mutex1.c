#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define WORK_SIZE 100

void *thread_produce();
void *thread_consumer();

pthread_mutex_t work_mutex; /* protects both work_area and time_to_exit */
int work_area[WORK_SIZE];

int time_to_exit = 0 , in=0 , out=0 , count=0;

int main() {
    pthread_t a_thread , b_thread;

    pthread_mutex_init(&work_mutex, NULL);

    pthread_create(&a_thread, NULL, thread_produce, NULL);
    pthread_create(&b_thread, NULL, thread_consumer, NULL);
 
    printf("\nWaiting for thread to finish...\n");
    pthread_join(a_thread, 0);
	pthread_join(b_thread, 0);
    printf("Thread joined\n");
    pthread_mutex_destroy(&work_mutex);
	return 0;
}

void *thread_consumer() {
	while(out!=1000){
		while(count == 0){
			sleep(1);
		}
		pthread_mutex_lock(&work_mutex);
		printf("%d ",work_area[out%100]);
		out++;
		count--;
        pthread_mutex_unlock(&work_mutex);
	}
    pthread_exit(0);
}

void *thread_produce() {
	while(in!=1000){
		while(count == 100){
			sleep(1);
		}
		pthread_mutex_lock(&work_mutex);
		work_area[in%100]=in;
		in++;
		count++;
	    pthread_mutex_unlock(&work_mutex);
	}
	pthread_exit(0);
}
