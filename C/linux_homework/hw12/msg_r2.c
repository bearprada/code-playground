
/* Here's the receiver program. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct quere{int q_number ;int data;};

int main()
{
    int Q1,Q2,i,sum;
    struct quere data1,data2;
    long int msg_to_receive = 0;

    Q1 = msgget((key_t)0050, 0666 | IPC_CREAT);
    
    if (Q1 == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    while(1) {
            msgrcv(Q1, (int *)&data1, sizeof(int) ,msg_to_receive , 0);

            if (data1.data==100) {
               break;
            }
            Q2 = data1.q_number;
            for(i=1,sum=1;i<data1.data;i++)
                sum *=i;
            data2.data = sum;
            data2.q_number=Q1;
            msgsnd(Q2, (void *)&data2, sizeof(struct quere) , 0);
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
