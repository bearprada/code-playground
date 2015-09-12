


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
    int Q1,Q2,buf;
    int running;
    long int msg_to_receive = 0;
    struct quere data1,data2;

    Q1 = msgget((key_t)0050, 0666 | IPC_CREAT);
    Q2 = msgget((key_t)0051, 0666 | IPC_CREAT);

    if (Q1 == -1||Q2 == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("Enter some number: ");
        scanf(" %d",&buf);
        
        data1.data=buf;
        data1.q_number=Q2;
        msgsnd(Q1, (void *)&data1, sizeof(struct quere), 0);
        
        if(data1.data==100){
            break;
        }
        
        msgrcv(Q2, (void *)&data2, sizeof(struct quere), msg_to_receive , 0);         
        printf("Ans: %d\n", data2.data);
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
