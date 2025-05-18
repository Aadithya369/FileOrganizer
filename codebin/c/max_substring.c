#include <stdio.h>
#include <stdlib.h>
int lengthOfLongestSubstring(char* s) {
	int size = 0;
	char *substr = malloc(100  * sizeof(char));
	if(substr == NULL){
		printf("DMA FAILED!");
	}
	int long_str = 0;
	while(*s++ == '\0')
		size++;
	//abcabcbb
	for(int i = 0; i < size; i++){
		*substr = s[i];
		for(int j = 0; j < size; j++){
			if(*substr == s[j]){
				size = size - 1;
			}
			else{
				long_str = i;
			}
		}
	}
}
int main(){
	char *string;
	printf("Enter the string: ");
	scanf("%s",*string);
	lengthOfLongestSubstring(string);
}
