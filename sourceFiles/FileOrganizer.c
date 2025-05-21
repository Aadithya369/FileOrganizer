#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#ifdef  _WIN32
	#include <direct.h>
	#define slash '\\'
#elif  __linux__
	#include <dirent.h>
	#include <sys/stat.h>
	#include <unistd.h>
	#include <sys/types.h>
	#define slash '/'
#endif

int main(){
	char location[100];
	char file_name[200];
	printf("PATH:");
	fgets(location,sizeof(location),stdin);
	location[strcspn(location,"\n")] = '\0';
	DIR *dir;
	while((dir = opendir(location)) == NULL){
		if(ENOENT == errno){
			printf("Enter a valid path\n");
		}
		else{
			printf("opendir() failed to open :(\n");
		}
		printf("PATH:");
		fgets(location,sizeof(location),stdin);
		location[strcspn(location,"\n")] = '\0';
	}
	location[strcspn(location,"\n")] = '\0';
	struct dirent *files;
	if(ENOENT == errno){
		perror("Error opening dirent");	
		return 1;
	}
	while((files = readdir(dir)) != NULL){
		char extension[20];
		int j = 0;
		int last_pos = -1;
		for(int i = strlen(files->d_name) - 1;i >= 0;i--){
			if(files->d_name[i] == '.'){
				last_pos = i;			
				break;
			}
		}
		if (last_pos == -1){
			continue;
		}
		for(int i = last_pos + 1;i < strlen(files->d_name);i++){
			extension[j++] = files->d_name[i];
		}
		extension[j] = '\0';

		char new_path[300];
		snprintf(new_path,sizeof(new_path),"%s%c%s",location,slash,extension);
		#ifdef _WIN32
			if(_mkdir(new_path) == -1){
				perror("_mkdir() failed :(\n");
				return 1;
			}
		#elif __linux__  
			if(access(new_path,F_OK ) == -1){
				if(mkdir(new_path,0755) == -1){
					perror("mkdir failed :( ");
					return 1;
				}
			}	
		#endif
		char command2[1024];
		char old_path[1000];
		snprintf(command2,sizeof(command2),"%s%c%s%c%s",location,slash,extension,slash,files->d_name);
		snprintf(old_path,sizeof(old_path),"%s%c%s",location,slash,files->d_name);
		rename(old_path,command2);
	}
		printf("FILES ORGANIZED!!!");
		return 0;
}
