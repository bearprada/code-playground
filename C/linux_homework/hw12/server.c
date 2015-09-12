
/* Here's the receiver program. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>

struct quere{int q_number ;int data;};

void *computing(void *arg);

int main()
{
    int Q1,Q2,i,sum;
    struct quere data1;
    long int msg_to_receive = 0;
    pthread_t p1;

    Q1 = msgget((key_t)7771, 0666 | IPC_CREAT);
    
    if (Q1 == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    while(1) {
            msgrcv(Q1, (void *)&data1, sizeof(struct quere) ,msg_to_receive , 0);
	    
	    if (data1.data==100) {
               break;
            }
	    pthread_create(&p1,NULL,computing,(void *)&data1);
            
    }

    if (msgctl(Q1, IPC_RMID, 0) == -1) {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    if (msgctl(Q2, IPC_RMID, 0) == -1) {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

void *computing(void *arg)
{
	struct quere *p=arg;
	int Q2,i,sum;

	Q2 = msgget((key_t)p->q_number, 0666 | IPC_CREAT);

        for(i=1,sum=1;i<p->data;i++)
                sum *=i;
				
        p->data = sum;
        msgsnd(Q2, (void *)p, sizeof(struct quere) , 0);	
	printf ("success!!\n");
	pthread_exit(NULL);
}
