#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int opt , tmp , x , y;

	if(argc<3){
		printf ("no enough paramater\n");
		return 0;
	}
	x = atoi(argv[2]);
	y = atoi(argv[3]);

    if((opt = getopt(argc, argv, "asdm")) != -1){ 
        switch(opt) {
        case 'a':
			tmp = x+ y;
			printf("ANS:%d\n",tmp);
			break;
        case 's':
			tmp = x - y ;
			printf("ANS:%d\n",tmp);
			break;
        case 'd':
			tmp = x / y;
			printf("ANS:%d\n",tmp);
			break;
        case 'm':
			tmp = x * y ;
			printf("ANS:%d\n",tmp);
			break;
        case '?':
            printf("unknown option: %c\n", optopt);
            break;
        }
	}

	return 0;
}
