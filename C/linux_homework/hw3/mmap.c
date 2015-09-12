#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define LEN (10)

main()
{
	FILE *fo;
	int fd;
	int A[LEN] , i , n;
	int *start;
// ------------inital--------------------
	fo = fopen("out","w");
	for( i=0 ; i<LEN ; i++)
		A[i] = i;
	fwrite(A,sizeof(int),LEN,fo);
	fclose(fo);

//          --------  mmap --------------

	fd = open("out", O_RDWR);
	start=(int *)mmap( 0 , LEN*sizeof(int) , PROT_READ|PROT_WRITE , MAP_SHARED , fd , 0 );

	for(i=0 ; i<LEN ;i++)
		start[i] = i*10;

	msync((void *)start,LEN*sizeof(int),MS_ASYNC);
	munmap((void *)start,LEN*sizeof(int));

	close(fd);

//----------------------test end--------------
	fo = fopen("out","r");
	fread(A,sizeof(int),LEN,fo);

	for( i=0 ; i<LEN ; i++)
		printf("%d\n",A[i]);

	fclose(fo);
}

