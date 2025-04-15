#include<semaphore.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
semt_t mutex;
int i=0;
void *thread(void* arg){
	int *p = (int*)arg;
	int mynum = *p;
	sem_wait(&mutex);
	printf("\nEntering Critical section. . .\n");
	printf("My thread ID is %u\n",mynum);
	i = i + 1;
	printf("After incrementing i = %d\n",i);
	sleep(4);
	printf("\nExiting Critical section. . .\n");
	sem_post(&mutex);
}
int main(){
	sem_init(&mutex, 0, 1);
	pthread_t t1, t2;
	pthread_create(&t1,NULL,thread,&t1);
	sleep(2);
	pthread_create(&t2,NULL,thread,&t2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	printf("\nExit main function\n");
	return 0;
}
