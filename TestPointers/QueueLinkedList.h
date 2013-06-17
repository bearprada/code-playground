//
//  QueueLinkedList.h
//  TestPointers
//
//  Created by RD Team on 6/17/13.
//  Copyright (c) 2013 Aplix. All rights reserved.
//

#ifndef TestPointers_QueueLinkedList_h
#define TestPointers_QueueLinkedList_h


typedef struct queue_item {
    int qid;
    struct queue_item * next;
    struct queue_item * prev;
} QueueItem;

void init_queue(QueueItem **head);
void add(int data, QueueItem *head);
void del(int id,QueueItem * h);
void search(int id, QueueItem *head, QueueItem* result);

#endif
