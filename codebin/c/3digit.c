#include <stdio.h>
#include <stdlib.h>
int main(){
	int number = 0;
	int k = 0;
	int *num_arr = malloc(sizeof(int)  * 20);
	int arr[] = {1,2,3};
	printf("The size of the array is : %ld\n",sizeof(arr)/sizeof(arr[0]));
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
		for(int j = i + 1; j < sizeof(arr)/sizeof(arr[0]) - 1;j++){
			 number = (arr[i] * 10 + arr[j]) * 10+ arr[j + 1];	
			 if(number % 10 != 0 && number % 2 == 0){
				num_arr[k] = number;
				k++;
			 }
		}
	}
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
		printf("%d",arr[i]);
	}
	free(num_arr);
}
