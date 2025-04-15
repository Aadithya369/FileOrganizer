#include <stdio.h>
int main(){
	FILE *file = fopen("testfile.txt","w");
	fputs("Hello world",file);
	return 0;
}
