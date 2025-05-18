#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int i = 10;
void *thread(void *arg){
	int *p = (int*)arg;
	int mynum = *p;
	pthread_mutex_lock(&mutex);
	printf("\nEntering critical section!\n");
	i = i+1;
	printf("%d",i);
	sleep(4);
	printf("\nExting critical section!");
	pthread_mutex_unlock(&mutex);
}
int main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread,&t1);
	sleep(4);
	pthread_create(&t2,NULL,thread,&t2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
