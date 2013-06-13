//
//  main.c
//  Sample Code of Merge Sort
//  Created by PRADA Hsiung on 6/13/13.
//  Copyright (c) 2013 PradaLab. All rights reserved.
//

#include <stdio.h>

void merge(int *left,int leftLen,int * right,int rightLen){
    int lidx = 0;
    int ridx = 0;
    int idx = 0;
    int tmp[leftLen+rightLen];
    while( lidx<leftLen && ridx<rightLen ){
        if(*(left+lidx) < *(right+ridx)){
            tmp[idx++] = *(left+(lidx++));
        }else{
            tmp[idx++] = *(right+(ridx++));
        }
    }
    
    while(lidx<leftLen){
        tmp[idx++] = *(left+(lidx++));
    }
    
    while(ridx<rightLen){
        tmp[idx++] = *(right+(ridx++));
    }
    //FIXME replace to array copy function
    int * start = left;
    for(int i=0;i<(leftLen+rightLen);i++,start++){
        *start = tmp[i];
    }
}

void merge_sort(int *arr,int len){
    if(len<=1) return;
    
    int halfLen = len/2;
    int *left=arr;
    int *right = arr+halfLen;
    int rLen =len-(halfLen);
    merge_sort(left,halfLen);
    merge_sort(right,rLen);
    merge(left,halfLen,right,rLen);
}

int main(int argc, const char * argv[])
{
    int arr[] = {1,5,6,66,5,4,8,888};
    merge_sort(&arr[0], 8);
    for(int i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}