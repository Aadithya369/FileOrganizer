#include<stdio.h>
#include<pthread.h>
void *computation(void *display);
int main(){
	pthread_t t1;
	pthread_t t2;
	long value1=10;
	long value2=20;
	pthread_create(&t1,NULL,computation,(void*)&value2);
	pthread_create(&t2,NULL,computation,(void*)&value2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("\nDear students\n");
	pthread_exit(NULL);
	return 0;
}
void *computation(void *display){
	long *num=(long *)display;
	printf("\nDisplay %ld\n",*num);
	return NULL;
}
