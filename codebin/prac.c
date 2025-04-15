
#Inl
#Inl
#Inl
#Inl
#Inl
#Inl
#Inl
#Inl
#Inl
#include<stdio.h>
int main(){
	int n = 12345;
	int arr[10];
	int i = 0;
	while(n!=0){
		arr[i] = n%10;
		n = n / 10;		
		i++;
	}
	for(int i = 0;i<5;i++){
		printf("%d",arr[i]);
	}
}
