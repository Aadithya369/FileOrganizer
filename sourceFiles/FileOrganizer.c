#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char location[100];
	char command[200];
	char read_buffer[100];
	char extension[20];
	printf("Enter the location:");
	fgets(location,sizeof(location),stdin);
	location[strcspn(location,"\n")] = '\0';
	int flag;
	char check_path[150];
	snprintf(check_path,sizeof(check_path),"sh -c '[ -d \"%s\" ]'",location);
	flag = system(check_path);
	while(flag !=0){
		printf("Please enter a valid path\n");
		printf("Enter the location:");
		fgets(location,sizeof(location),stdin);
		location[strcspn(location,"\n")] = '\0';
		snprintf(check_path,sizeof(check_path),"sh -c '[ -d \"%s\" ]'",location);
		flag = system(check_path);
	}
	location[strcspn(location,"\n")] = '\0';
	snprintf(command,sizeof(command),"ls -1  %s",location);
	FILE *p1 = popen(command,"r");	
	FILE *list = fopen("lists.txt","w+");
	if(p1 == NULL){
		perror("Error running the process p1");
		return 1;
	}
	while(fgets(read_buffer,sizeof(read_buffer),p1)){
		fputs(read_buffer,list);	
	}
	pclose(p1);
	rewind(list);
	while(fgets(read_buffer,sizeof(read_buffer),list)){
		read_buffer[strcspn(read_buffer,"\n")] = '\0';
		memset(extension,0,sizeof(extension));
		read_buffer[strcspn(read_buffer,"\n")] = '\0';
		int j = 0;
		int last_pos = -1;
		for(int i = strlen(read_buffer) - 1;i >= 0;i--){
			if(read_buffer[i] == '.'){
				last_pos = i;			
				break;
			}
		}
		if (last_pos == -1){
			continue;
		}
		for(int i = last_pos + 1;i < strlen(read_buffer);i++){
			extension[j++] = read_buffer[i];
		}
		extension[j] = '\0';
		char command1[300];
		snprintf(command1,sizeof(command1),"mkdir %s/%s",location,extension);
		system(command1);
		char command2[3000];
		snprintf(command2,sizeof(command2),"mv %s/%s %s/%s",location,read_buffer,location,extension);
		system(command2);
	}
		printf("FILES ORGANIZED!!!");
		fclose(list);
		return 0;
}
