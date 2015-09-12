int max (int *A , int len)
{
    int i , big ;
    big = A[0];
    for( i=1 ; i<len ; i++){
         if( A[i] > big ){
             big = A[i];
         }
    }
    return big;
}
