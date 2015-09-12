#include <stdio.h>

void SWAP(int *A,int a , int b)
{
	int temp;	
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

void BOBsort(int *A , int len)
{
     int i,j;
     
     for(i=0 ; i<len-1 ; i++){
         for(j=i+1; j<len ; j++){
             if(A[j]<A[i])
                 SWAP(A,j,i);
         }
     }         
}

int main()
{
	int i , n ,A[10];

	FILE *datain,*dataout;
//   ------------------rand number--------------
	datain = fopen("datain","w");
	srand(time(NULL));
	for(i=0;i<10;i++){
		n = rand()%100+1;
		fprintf(datain,"%d ", n );
	}
	fclose(datain);

//    ---------------load and sort  -------------------
	datain = fopen("datain","r+");
	for(i=0;i<10;i++){
		fscanf(datain,"%d ",&A[i]);
	}
	
	BOBsort(A,10);

	dataout = fopen ("dataout" , "w");
	for(i=0;i<10;i++)
		fprintf(dataout,"%d ",A[i]);

	fclose(datain);	
	fclose(dataout);
}
