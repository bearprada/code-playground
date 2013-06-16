//
//  LinkedList.c
//  TestPointers
//
//  Created by PRADA Hsiung on 13/6/16.
//  Copyright (c) 2013年 Aplix. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

Item * __insert(int data,Item *p, Item *h){
    Item * item = (Item *)malloc(sizeof(Item));
    item->id = data;
    item->next = h;
    item->prev= p;
    p->next = item;
    h->prev = item;
    return p->next;
}

void insert(int data, Item *h){
    Item *p = h;
    while(p->next!=h){
        p = p->next;
    }
    __insert(data,p,h);
}

void find(int id, Item *h, Item* r){
    Item * p = h;
    while(p->next!=h){
        if(p->id==id){
            *r = *p;
            return;
        }
        p = p->next;
    }
}


// delete
void remove_node(int id,Item * h){
    Item *p = h;
    while(p->next!=h){
        if(p->id==id){
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            return;
        }
        p = p->next;
    }
}
