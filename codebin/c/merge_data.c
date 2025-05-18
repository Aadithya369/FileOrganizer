#include <stdio.h>
int main(){
	int arr1[] = {5,10,15,20};
	int arr2[] = {1,2,3,4};
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	int temp = 0;
	for(int  i = 0;i < size1; i++){
		for(int j = 0; j < size2; j++){
			if(arr1[i] > arr2[j]){
				temp = arr1[i];
				arr1[i] = arr2[j];
				arr2[j] = temp;
			}
		}
	}
	for(int i = 0; i < size2;i++){
		for(int j = 0;j < size2; j++){
			if(arr2[i] < arr2[j]){
				temp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = temp;
			}
		}
	}
	for(int i = 0;i < size1;i++){
		printf("%d ",arr1[i]);
	}
	printf("\n");
	for(int j = 0;j < size2;j++){
		printf("%d ",arr2[j]);
	}
}
