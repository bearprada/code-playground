#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void atoA(char A[])
{
   char a , i=0;
   while(A[i]!='\0'){
		if(A[i]>='A' && A[i]<='Z')
			a=A[i]+32;
	    else if (A[i]>='a' && A[i]<='z')
			a=A[i]-32;
		else
			a=A[i];
		A[i] = a ;
		i++;
   }	
} 

int main()
{
    int file_pipes[2];
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    if (pipe(file_pipes) == 0) {
        fork_result = fork();
        if (fork_result == 0) {
			while(1){
				read(file_pipes[0], buffer, BUFSIZ);
				atoA(buffer);
				printf("Read  %s\n", buffer);
				memset(buffer, '\0', sizeof(buffer));
			}
        }
        else {
			while(1){
				scanf("%s",&buffer);
	            write(file_pipes[1], buffer,strlen(buffer));
				printf("Wrote %s\n", buffer);
			}
        }
	}
	return 0;
}
