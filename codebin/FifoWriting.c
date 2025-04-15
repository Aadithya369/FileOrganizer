#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	const char *Fifo_name = "myfifo";
	if(mkfifo(Fifo_name,0666)==-1){
		perror("mkfifo failed");
		return 1;
	}
	int fd = open(Fifo_name,O_WRONLY);
	if(fd == -1){
		perror("open failed");
		return 1;
	}
	const char *message = "Hello world!";
	write(fd,message,sizeof(message));
	close(fd);
	return 0;
}

