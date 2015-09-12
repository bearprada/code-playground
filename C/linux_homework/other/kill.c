
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
    int Q1,i;
    
    for(i=0;i<10000;i++){   
        Q1 = msgget((key_t)i, 0666 | IPC_CREAT);
        msgctl(Q1, IPC_RMID, 0) ;
    }

    exit(EXIT_SUCCESS);
}
