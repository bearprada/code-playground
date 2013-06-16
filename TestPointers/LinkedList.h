//
//  LinkedList.h
//  TestPointers
//
//  Created by PRADA Hsiung on 13/6/16.
//  Copyright (c) 2013年 Aplix. All rights reserved.
//

#ifndef TestPointers_LinkedList_h
#define TestPointers_LinkedList_h

typedef struct item {
    int id;
    char content[10];
    struct item * next;
    struct item * prev;
} Item;

void insert(int data, Item *h);
void find(int id, Item *h, Item* r);
void remove_node(int id,Item * h);
#endif
