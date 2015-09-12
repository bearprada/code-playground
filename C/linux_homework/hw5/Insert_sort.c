#include <stdio.h>
#include <stdlib.h>

struct node{int data;struct node *next;};
typedef struct node NODE;

	
int main()
{
	NODE *p,*newnode,*before,*head=NULL;
	int i , n , counter = 5;

	while(counter--){
		newnode = (NODE *)malloc(sizeof(NODE));
		scanf (" %d",&newnode->data);
		newnode->next = NULL;

		if(head == NULL){
			head = newnode;
		}else{
			//���J�Ƨ�
			p = before = head;
			//�w��
			while(p!=NULL){
				if( newnode->data < p->data ) 
					break;
				else{
					before = p;
					p = p->next;
				}
			}
			//�P�_�O���O�b�Y��
			if(p!=before){
				newnode->next = p;
				before->next = newnode;
			}else{
				newnode->next = before;
				head = newnode;
			}
		}
	}
	//��ܵ��G
	p = head;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	return 0;
}
