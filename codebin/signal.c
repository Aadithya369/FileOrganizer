#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void mySignalHandler(int mySignal);
int main(){
	int i=1;
	signal(SIGTERM,mySignalHandler);
	signal(SIGKILL,mySignalHandler);
	while(i > 0){
		printf("%d\n",i);
		i++;
		sleep(1);
	}
	return 0;
}
void mySignalHandler(int mySignal){
	if(mySignal == SIGTERM){
		printf("My Handle with signal %d",mySignal);
	}
	if(mySignal == SIGKILL){
		printf("SIGKLILL signal received");
	}

