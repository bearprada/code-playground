#include <stdio.h>
#include <stdlib.h>
#define SIZE 10240*10240

int A[SIZE] , B[SIZE] , C[SIZE];

int main() {
	int i;
	for(i=0;i<SIZE;i++)
		A[i] = B[i] = 1;
	for(i=0 ; i<SIZE;i++)
		C[i] = A[i] + B[i];
	for(i=0;i<SIZE;i++)
		printf ("%d ",C[i]);
    return 0;
}

