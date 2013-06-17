//
//  main.c
//  Sample Code of Merge Sort
//  Created by PRADA Hsiung on 6/13/13.
//  Copyright (c) 2013 PradaLab. All rights reserved.
//

#include <stdio.h>
#include "QueueLinkedList.h"

void test_queue_linked_list(){
    QueueItem * head = NULL;
    init_queue(&head);
    
    for(int i=1;i<=5;i++){
        add(i,head);
    }
    del(3,head);
    del(3,head);
    
    QueueItem result;
    search(3,head,&result);
    printf(" find result : current %d, prev %d , next %d\n",result.qid,result.prev->qid,result.next->qid);
}

int main(int argc, const char * argv[])
{
//    test_linked_list();
//    test_merge_sort();
    test_queue_linked_list();
    return 0;
}

