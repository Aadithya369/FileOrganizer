#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
void insertAtEnd(struct Node** head, int data){
	struct Node* newNode=createNode(data);
	struct Node* temp=*head;
	if(*head==NULL){
		*head=newNode;
		return;
	}
	while(temp-)
}
