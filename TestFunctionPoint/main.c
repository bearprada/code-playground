//
//  main.c
//  TestFunctionPoint
//
//  Created by RD Team on 6/10/13.
//  Copyright (c) 2013 Aplix. All rights reserved.
//
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int jimmy(char op, int (*func)(int, int)) {
    if (op == '+') {
        return (*func)(1, 2);
    }
    return -1;
}

typedef struct node{
    int id;
    struct node * next;
    struct node * prev;
}Node;

Node * head;
Node * tail;

void addNode(Node * n){
    if(head==NULL){
        head=n;
        tail=head;
    }else{
        n->prev = tail;
        tail->next = n;
        tail = tail->next;
    }
}

void delete(int id){
    Node * p = head;
    while(p!=NULL){
        if(p->id==id){
            p->prev->next = p->next;
            p->next->prev = p->prev;
            return;
        }
        p = p->next;
    }
}

void blub_sort(){
    Node * p = head;
    while(p!=NULL){
        //TODO double loop
        if(p->next!=NULL){
        if(p->id < p->next->id ){
            Node * a = p;
            Node * b = p->next;
            Node * tmp = a->prev;
            a->prev = b;
            a->next = b->next;
            b->prev = a;
            b->next = tmp;
        }
        }
        p = p->next;
    }
}

void merge_sort(){
    
}

void addToBottom(int id){
    Node * n = (Node *)malloc(sizeof(Node));
    n->id = id;
    addNode(n);
}


int main(void) {
    /*int (*func)(int, int) = add;
    printf("%d\n", jimmy('+', func));
    */
    addToBottom(7);
    addToBottom(1);
    addToBottom(2);
    addToBottom(3);
    addToBottom(4);
    addToBottom(5);
    
    delete(2);
    delete(6);
    
    blub_sort();
    
    Node * p = head;
    while(p!=NULL){
        printf("%d ",p->id);
        p = p->next;
    }
    
    return 0;
}

