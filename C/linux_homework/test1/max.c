#include<stdio.h>
#include<math.h>
#include<stdlib.h>

main(int argc,char *argv[])
{
    int a , b , c , big ;
    a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	
	if( a > b && a>c )
		exit (a);
	else if( b > a && b>c )
		exit (b);
	else if( c>b && c>a )
		exit (c);
}
