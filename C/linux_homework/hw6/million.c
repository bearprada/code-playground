#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    int n ,i , limit ,sum;	
	int stat_val ;

    scanf(" %d",&n);
	sum =0;
    pid = fork();

    switch(pid) {
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			for(i=n/2+1 ; i<=n ; i++)
				sum +=i;
			break;
		default:
			limit = n/2;
			for(i=1 ; i<=limit ;i++)
				sum +=i ;
			wait(&stat_val);
			if(WIFEXITED(stat_val))
				sum += WEXITSTATUS(stat_val);
			else
				printf("Child terminated abnormally\n");
			break;
	}
	
		printf ("%d ",sum);
	
		exit (sum);
}
