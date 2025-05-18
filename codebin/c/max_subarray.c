#include <stdio.h>
int maxSubArray(int *nums, int numsSize){
	int max = nums[0];
	int current_sum = nums[0];
	for(int i = 0;i < numsSize;i++){
		if(current_sum < 0){
			current_sum = nums[i];
		}
		else{
			current_sum += nums[i];
		}
		if(current_sum > max){
			max = current_sum;
		}
	}
	return max;
}
int main(){
	int nums[] = {-2,-3};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	printf("%d",maxSubArray(nums,numsSize));
}
