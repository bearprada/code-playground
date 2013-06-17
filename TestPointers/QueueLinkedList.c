//
//  QueueLinkedList.c
//  TestPointers
//
//  Created by RD Team on 6/17/13.
//  Copyright (c) 2013 Aplix. All rights reserved.
//

#include <stdio.h>
#include "QueueLinkedList.h"

void init_queue(QueueItem **head){
    QueueItem *tmp =(QueueItem *)malloc(sizeof(QueueItem));
    tmp->qid = -1;
    tmp->next = tmp;
    tmp->prev = tmp;
    *(head) = tmp;
}

void add(int data, QueueItem *head){
    if(head==NULL)
        return;
    QueueItem *tmp, *p = head;
    while(p->next!=head){
        p = p->next;
    }
    tmp = (QueueItem *)malloc(sizeof(QueueItem));
    tmp->qid = data;
    tmp->next = head;
    tmp->prev = p;
    p->next = tmp;
    head->prev = tmp;
}

void del(int id,QueueItem * head){
    if(head==NULL)
        return;
    QueueItem *p = head;
    while(p->next!=head){
        if(p->qid==id){
            QueueItem *a = p->prev;
            QueueItem *b = p->next;
            a->next =b;
            b->prev =a;
            free(p);
            return;
        }
    }
}

void search(int id, QueueItem *head, QueueItem* result){
    if(head==NULL) return;
    QueueItem *p = head;
    while(p->next!=head){
        if(p->qid==id){
            result = p;
            return;
        }
    }
}