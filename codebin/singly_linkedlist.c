#include<stdio.h>
#include<stdlib.h>
struct playList{
	char *song;
	int no_of_song;
	int *next;
	int *prev;
}
void addSong(){
	struct playList newNode=(struct playList*)malloc(sizeof(struct playList));
	printf("Add the song:");
	srtuct playList *head=NULL;
	struct playList *tail=NULL;
	if(head==NULL){
		head=newNode;
		scanf("%s",head->song);
		tail=head;
	}
	else if(head->next!=NULL){
		head->next=newNode;
		
	}
}
