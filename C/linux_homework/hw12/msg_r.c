/* Here's the receiver program. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    int Q1,Q2,i,sum,data;
    long int msg_to_receive = 0;

    Q1 = msgget((key_t)0030, 0666 | IPC_CREAT);
    Q2 = msgget((key_t)0031, 0666 | IPC_CREAT);
    
    if (Q1 == -1||Q2 == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    while(1) {
            msgrcv(Q1, (int *)&data, sizeof(int) ,msg_to_receive , 0);

            if (data==100) {
               break;
            }
                        
            for(i=1,sum=1;i<data;i++)
                sum *=i;
            
            msgsnd(Q2, (int *)&sum, sizeof(int) , 0);
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
