#include<stdio.h>
int main(){
	int arr[] = {1,2,3,-4,-5};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0;i < size;i++){
		if(size == 0){
			printf("[]");
		}
		else if(arr[i] < 0){
			arr[i] = arr[i] * -1; 
		}
		else if(arr[i] > 0){
			arr[i] = arr[i] * -1;
		}
	}
	for(int i = 0;i<size;i++){
		printf("%d",arr[i]);
	}

}
