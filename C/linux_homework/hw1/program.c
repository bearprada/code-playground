#include "mylib.h"
#include <time.h>

main()
{
      int A[10] , i;
      
      srand(time(NULL));
      
      for( i=0 ; i<10 ; i++)
           A[i] = rand()%30;
      
      bsort(A,10);
      for( i=0 ; i<10 ; i++)
           printf("%d ",A[i]);
      printf("\n");
      
      printf("MAX:%d\n",max(A,10));
      printf("SUM:%d\n",sum(A,10));
      
}
