/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sockfd;
    int len,i;
    struct sockaddr_in address;
    int result;
	int number[100];
	int sum;

/*  Create a socket for the client.  */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket, as agreed with the server.  */

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 413;
    len = sizeof(address);

/*  Now connect our socket to the server's socket.  */

    result = connect(sockfd, (struct sockaddr *)&address, len);

    if(result == -1) {
        perror("oops: client2");
        exit(1);
    }

/*  We can now read/write via sockfd.  */
	
	for(i=0 ; i<100; i++)
		number[i]=1;
    write(sockfd, number, sizeof(int)*100);
    read(sockfd, &sum, sizeof(int));
    printf("from server = %d\n", sum);
    close(sockfd);
    exit(0);
}
