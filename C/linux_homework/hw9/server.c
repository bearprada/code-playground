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
    int number=1,result;

	while(1){
		scanf(" %d",&number);
		send_fifo_fd = open(NAME1, O_WRONLY);
		write(send_fifo_fd, &number, sizeof(number));
		if(number==-1) break;

		recive_fifo_fd = open(NAME2, O_RDONLY);
        read(recive_fifo_fd, &result, sizeof(result));
		printf ("%d result : %d\n",getpid(),result);
	}
    close(send_fifo_fd);
	close(recive_fifo_fd);
    return 0;
}

