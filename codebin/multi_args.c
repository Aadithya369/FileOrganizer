#include<stdio.h>
#include<pthread.h>
void *computation(void *display);
int a[]={1,2};
int main(){
	pthread_t tid;
	void *retval;
	pthread_create(&tid,NULL,computation,(void*)a);
	pthread_join(tid,&retval);
	printf("\nMain thread\n");
	printf("\nThread Return value is %d\n",(int *)retval);
	return 0;
}
void *computation(void *display){
	int *b=(int *)display;
	int sum=b[0]+b[1];
	printf("\nInside thread");
	printf("The sum is :%d\n",sum);
	pthread_exit((void*)sum);
}
