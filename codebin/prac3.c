#include<stdio.h>
int main(){
	int gallons;
	int distance;
	printf("Enter the distance: ");
	scanf("%d",&distance);
	printf("Gallons left ?: ");
	scanf("%d",&gallons);
	if(gallons * 25 == distance){
		printf("true");
	}
	else{
		printf("false");
	}
}
