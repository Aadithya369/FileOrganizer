#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	if(argc != 2){
		fprintf(stderr,"usag: %s <number>\n",argv[0]);
		return 1;
	}
	int num = atoi(argv[1]);
	if(num % 2 == 0){
		printf("Even number");
	}
	else{
		printf("odd number");
	}
	return 0;
}
