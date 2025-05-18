#include <stdio.h>
int main(){
	FILE *file = fopen("~/Desktop/side_projects/todolistcli/tasks.txt","r");
	if(file == NULL){
		printf("error opening the file");
		return 1;
	}
	if(sizeof(file) == 0){
		printf("no size");
	}
	printf("size: %ld",sizeof(file));
}
