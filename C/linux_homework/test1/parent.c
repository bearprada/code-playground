//⊿Τ快猭printㄏノよΑ,把计单戈癟
//⊿Τр祘跑计暗˙笆

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
static char *f_argv[]={"1","2","3","4",0};
main()
{
    pid_t pid;
    int ch,a,b,c,n,ans;
	int stat_val ;
	
	char temp[10];

	while(1){
		printf ("1.ADD:\n2.FACT:\n3.MAX:\nQuit:\n");
		scanf(" %d",&ch);

		pid = fork();

		if(pid==0){
			switch(ch){
				case 1:

					f_argv[0]="add";
				    scanf(" %d %d",&a,&b);
					sprintf(temp,"%d",a);
					f_argv[1]=temp;
					sprintf(temp,"%d",b);
					f_argv[2]=temp;
					f_argv[3]=0;
					execvp("./add",f_argv);
					break;

				case 2:

					f_argv[0]="fact";
					scanf(" %d",&n);
					sprintf(temp,"%d",n);
					f_argv[1]=temp;
					f_argv[2]=0;
					execvp("./fact",f_argv);
					break;

				case 3:
					f_argv[0]="max";
					scanf(" %d %d %d",&a,&b,&c);
					sprintf(temp,"%d",a);
					f_argv[1]=temp;
					sprintf(temp,"%d",b);
					f_argv[2]=temp;
					sprintf(temp,"%d",c);
					f_argv[3]=temp;
					f_argv[4]=0;
					execvp("./max",f_argv);
					break;

				default :
					printf ("Leave a system!!\n");
					exit (0);
			}//switch
		}else{//pid loop
			if(ch==4)  exit(0);
			wait(&stat_val);
			if(WIFEXITED(stat_val))
				ans = WEXITSTATUS(stat_val);
			printf ("PID:%d	ANS:%d\n",pid , ans);
		}
	}//while
    exit(0);
}
