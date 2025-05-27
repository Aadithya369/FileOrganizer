#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	char location[500];
	char file_name[30];
	DIR *dir;
	struct dirent *files;
	// get the PATH from the user and validate it 
	do{
		if(ENOENT == errno){
			printf("Enter a valid path:\n");
		}
		printf("PATH:");
		fgets(location,sizeof(location),stdin);
		location[strcspn(location,"\n")] = '\0';
	}while((dir = opendir(location)) == NULL);
	while((files = readdir(dir)) != NULL){
		if(files->d_type == 4) //this is to avoid the program to treat the directories as files
			continue;
		char *pos = strrchr(files->d_name,'.');
		char dir_name[850];
		char dir_path[1350];
		char old_path[900];
		char new_path[1700];
		if(pos!=NULL){
			if(files->d_name[0] == '.')//skip hidden files
				continue;
			strcpy(dir_name,pos + 1);//extract the extension name
			snprintf(dir_path,sizeof(dir_path),"%s/%s",location,dir_name);
			mkdir(dir_path,0755);
			snprintf(old_path,sizeof(old_path),"%s/%s",location,files->d_name);
			snprintf(new_path,sizeof(new_path),"%s/%s/%s",location,dir_name,files->d_name);
			rename(old_path,new_path);//move the files to the respective sub directories
		}
		else{
			if(files->d_name[0] == '.')
				continue;
			snprintf(dir_name,sizeof(dir_name),"%s/%s",location,files->d_name);	
			snprintf(dir_path,sizeof(dir_path),"%s/extension_less",location);
			mkdir(dir_path,0755);
			snprintf(old_path,sizeof(old_path),"%s/%s",location,files->d_name);
			snprintf(new_path,sizeof(new_path),"%s/extension_less/%s",location,files->d_name);
			rename(old_path,new_path);
		}
	}
		printf("FILES ORGANIZED!!!");
		return 0;
}
