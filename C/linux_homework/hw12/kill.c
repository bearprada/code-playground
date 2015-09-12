
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

    Q1 = msgget((key_t)7771, 0666 | IPC_CREAT);
    Q2 = msgget((key_t)7000, 0666 | IPC_CREAT);
    
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
