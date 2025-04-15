#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char location[200];
	fgets(location,sizeof(location),stdin);
	char location2 [200];
	snprintf(location2,"ls -1  %s",location);
	char read_buffer[100];
	char extension[20];
	FILE *p1 = popen(location2,"r");	
	FILE *list = fopen("lists.txt","w+");
	if(p1 == NULL){
		perror("Error running the p1");
		return 1;
	}
	while(fgets(read_buffer,sizeof(read_buffer),p1)){
		fputs(read_buffer,list);	
	}
	pclose(p1);
	rewind(list);
	while(fgets(read_buffer,sizeof(read_buffer),list)){
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
		snprintf(command1,sizeof(command1),"mkdir -p %s/%s",location2,extension);
		system(command1);
		char command2[300];
		snprintf(command2,sizeof(command2),"mv %s/*%s %s/%s",location2,location2,extension,extension);
		system(command2);
	}

		fclose(list);
		return 0;
}
