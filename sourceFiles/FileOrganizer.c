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
#else
	#error "Unsupported platform"
#endif

int main(){
	char *location = malloc(sizeof(char));
	char *file_name = malloc(sizeof(char));
	DIR *dir;
	struct dirent *files;
	printf("PATH:");
	fgets(location,sizeof(location),stdin);
	location[strcspn(location,"\n")] = '\0';
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
	while((files = readdir(dir)) != NULL){
		char *pos = strrchr(files->d_name,'.');
		char *dir_name = malloc(sizeof(char));
		char *dir_path = malloc(sizeof(char));
		char *old_path = malloc(sizeof(char));
		char *new_path = malloc(sizeof(char));
		if(pos!=NULL){
			if(files->d_name[0] == '.')
				continue;
			strcpy(dir_name,pos + 1);
			snprintf(dir_path,sizeof(dir_path),"%s%c%s",location,slash,dir_name);
			#ifdef WIN_32
				_mkdir(dir_path);
			#elif __linux__
				mkdir(dir_path,0755);
			#else
				printf("Unsupported OS");
			#endif
			
			snprintf(old_path,sizeof(old_path),"%s%c%s",location,slash,files->d_name);
			snprintf(new_path,sizeof(new_path),"%s%c%s%c%s",location,slash,dir_name,slash,files->d_name);
			rename(old_path,new_path);
		}
		else{
			if(files->d_name[0] == '.')
				continue;
			snprintf(dir_name,sizeof(dir_name),"%s%c%s",location,slash,files->d_name);	
			snprintf(dir_path,sizeof(dir_path),"%s%cextension_less",location,slash);
			#ifdef WIN_32
				_mkdir(dir_path);
			#elif __linux__
				mkdir(dir_path,0755);
			#else
				printf("Unsupported OS");
			#endif

			snprintf(old_path,sizeof(old_path),"%s%c%s",location,slash,files->d_name);
			snprintf(new_path,sizeof(new_path),"%s%cextension_less%c%s",location,slash,slash,files->d_name);
			rename(old_path,new_path);
		}
	}
		printf("FILES ORGANIZED!!!");
		return 0;
}
