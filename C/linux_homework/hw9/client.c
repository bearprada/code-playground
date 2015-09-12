#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#define NAME1 "fifo1"
#define NAME2 "fifo2"

int main()
{
    int send_fifo_fd, recive_fifo_fd;
    int i,sum,number=1;

	mkfifo(NAME1, 0777);
	mkfifo(NAME2, 0777);

    while(1){	
		recive_fifo_fd = open(NAME1, O_RDONLY);
        read(recive_fifo_fd, &number, sizeof(number));
	    printf ("%d recive : %d\n",getpid(),number);
		if(number==-1) break;

		sum=1;
	    for(i=1;i<=number;i++)
		   sum *= i;

		send_fifo_fd = open(NAME2, O_WRONLY);
		write(send_fifo_fd, &sum, sizeof(sum));
	}
    close(send_fifo_fd);
    close(recive_fifo_fd);
    return 0;
}

