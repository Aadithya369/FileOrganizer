#include<stdio.h>
#include<string.h>
int main(){
	char name[5][20]={"Aadithya","Subiksha","Tharun","Nithya","Pranav karthic"};
	int match = 8;
	for(int i = 0;i < sizeof(name) / sizeof(name[0]);i++){
		if(strlen(name[i]) == 8){
			printf("%s",name[i]);
		}
	}
}
