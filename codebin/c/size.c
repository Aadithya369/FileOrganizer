#include <stdio.h>
int main(){
	int size = 0;
	int size_i = 0;
	char *s = "abcd";
	while(s[size_i] != '\0'){
	    size++;
	    size_i++;
    	}
	printf("%d",size);
}
