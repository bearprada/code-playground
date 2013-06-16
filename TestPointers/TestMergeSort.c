//
//  TestMergeSort.c
//  TestPointers
//
//  Created by PRADA Hsiung on 13/6/16.
//  Copyright (c) 2013年 Aplix. All rights reserved.
//

#include <stdio.h>
#import "MergeSort.h"

void test_merge_sort(){
    int arr[] = {1,5,6,66,5,4,8,888};
    merge_sort(&arr[0], 8);
    for(int i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
}
