#include <stdio.h>
int main(){
	int arr[] = {1,2,3,3};
	int temp = 0;
	int repeated = 0;
	int missing = 0;
	int end = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0;i < end; i++){
		for(int j = 0; j < end;j++){
			if(arr[i] < arr[j]){
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for(int i = 0;i < end - 1;i++){
		if(arr[i] == arr[i+1]){
			repeated = arr[i];
		}
		if(arr[i]+1 < arr[i+1]){
			missing = arr[i] + 1;
		}
	}
	if(missing == 0 && arr[end - 1] != end){
		missing = end;
	}
	printf("%d,%d\n",repeated,missing);
}
