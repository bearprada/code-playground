//
//  TestLinkedList.c
//  TestPointers
//
//  Created by PRADA Hsiung on 13/6/16.
//  Copyright (c) 2013年 Aplix. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

void test_linked_list(){
    Item * head = (Item *)malloc(sizeof(Item));
//    Item *tail = head;
    head->id = -1;
    head->prev = head;
    head->next = head;
    
    for(int i=1;i<=5;i++){
        insert(i,head);
        //tail = insert2(i,tail,head);
    }
    remove_node(3,head);
    remove_node(3,head);
    
    Item result;
    find(-1,head,&result); // it's work
    printf(" find result : current %d, prev %d , next %d\n",result.id,result.prev->id,result.next->id);
}