#include<stdio.h>
#include<stdlib.h>

main(int argc,char *argv[])
{
   int n=atoi(argv[1]);
   int i;
   int sum=1;
   for(i=1;i<=n;i++)
      sum=sum*i;
   exit(sum);
}
