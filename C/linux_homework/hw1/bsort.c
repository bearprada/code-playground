void bsort (int *A , int len)
{
    int i , flag=1 , temp;
    
    while(flag!=0){
        flag = 0;
        
        for( i=0 ; i<len-1 ; i++){
             if( A[i] > A[i+1] ){
             temp = A[i];
             A[i] = A[i+1];
             A[i+1]=temp;
             flag++;
             }
         }
    }
}
