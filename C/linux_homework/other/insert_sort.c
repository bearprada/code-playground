#include <stdio.h>
#include <stdlib.h>

struct node{int data;struct node *next;}*head=NULL,*newnode;
typedef struct node NODE;

void insert_sort() 
{
	NODE *p , *before;
	
	p = before = head;

	while(p!=NULL){
		if( newnode->data < p->data ){
			break;
		}else{
			before = p ;
			p = p->next;
		}
	}
	
	if(p==before){
		newnode->next = p;
		head = newnode;
	}else{
		before->next = newnode;
		newnode->next = p;
	}
	
}
			
	
int main()
{
	NODE *p,*newnode,*before;
	int i , n , counter = 5;

	while(counter--){
		newnode = (NODE *)malloc(sizeof(NODE));
		scanf (" %d",&newnode->data);
		newnode->next = NULL;
		if(head == NULL)
			head = newnode;
		else{
			insert_sort();
			/*
		p = before = head;
		while(p!=NULL){
		if( newnode->data < p->data ){
			break;
		}else{
			before = p ;
			p = p->next;
		}
		}
	newnode->next = p;

		if(before==head)
		head = newnode;
		else
		before->next = newnode;
		*/
		}
		free(newnode);
	}
	//顯示結果
	p = head;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	return 0;
}
