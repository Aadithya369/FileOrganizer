#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	pid_t pid = fork ();
	if(pid < 0){
		printf("Fork failed!\n");
		return 1;
	}
	else if(pid == 0){
		execl("./ForkChild","ForkChild","42",NULL);
		perror("excel failed");	
	}
	else{
		printf("I am Parent process and my pid is %d and my parent PID is %d\n",getpid(),pid);
		printf("Child process completed");
	}
	return 0;
}
