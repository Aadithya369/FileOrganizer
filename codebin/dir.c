#include <dirent.h>
#include <stdio.h>
int main(){
	DIR *dir = opendir("/home/aadithya/Desktop/codebin");
	if(dir == NULL){
		perror("Error");
	}
	struct dirent *file;
	while((file = readdir(dir))!=NULL){
		printf("%s",file->d_name);
	}
}
