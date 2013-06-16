//
//  MergeSort.c
//  TestPointers
//
//  Created by PRADA Hsiung on 13/6/16.
//  Copyright (c) 2013年 Aplix. All rights reserved.
//

#include <stdio.h>
#include "MergeSort.h"

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


