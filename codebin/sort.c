#include <stdio.h>
int main(){
	int arr1[] = {1,5,9,10,15,20};
	int arr2[] = {2,3,8,13};
	int temp = 0;
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	for(int i = 0;i < size1;i++){
		for(int j = 0;j < size1;j++){
			if(arr1[i] < arr1[j]){
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = arr1[i];
			}
			if(i <  size2 && j < size2){
				if(arr2[i] < arr2[j]){
					temp = arr2[i];
					arr2[i] = arr2[j];
					arr2[j] = temp;
				}
			}
		}
	}
	for(int i = 0; i < size2; i++){
		printf("%d\n",arr2[i]);
	}
}
