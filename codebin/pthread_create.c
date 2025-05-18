#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *printid(void *t1){
	long *Myid=(long *)t1;
	printf("\nDear Students.I m Thread with ID %ld \n",*Myid);
}
int main(){
	pthread_t t1;
	pthread_create(&t1,NULL,printid,(void*)&t1);
	pthread_join(t1,NULL);
	printf("I have been waiting for the thread t1 to end oof!");
	pthread_exit(NULL);
	return 0;
}
