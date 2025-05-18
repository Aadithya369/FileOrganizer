#include<pthread.h>
#include<stdio.h>
void *computation();
int main(){
	pthread_t thread1;
	pthread_create(&thread1,NULL,computation,NULL);
	pthread_join(thread1,NULL);
	printf("\nDear Students\n");
	pthread_exit(NULL);
	return 0;
}
void *computation(){
	printf("\nWelcome\n");
	return NULL;
}
