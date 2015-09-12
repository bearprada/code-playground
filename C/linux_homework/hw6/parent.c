#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    int n;
	char *f_argv[] ={"fact" , "0" , 0 };	
	char temp[10];

	while(1){
		scanf(" %d",&n);
		sprintf (temp , "%d" , n);

		f_argv[1] = temp;	
		pid = fork();

		if(pid==0)
			execvp("./fact",f_argv);
	}
    exit(0);
}
