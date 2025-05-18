#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	char buffer[1024];
	fp = popen("ls","r");
	if(fp == NULL){
		perror("popen failed!");
		return 1;
	}
	while(fgets(buffer,sizeof(buffer),fp)!=NULL){
		printf("%s",buffer);
	}
	int status = pclose(fp);
	printf("\ncommand exit status: %d",status);
	return 0;
}
