int sum (int *A , int len)
{
    int i , sum = 0 ;
    for( i=0 ; i<len ; i++){
        sum+= A[i];
    }
    return sum;
}

