#include<iostream>
int main(){
	int land[3][3];
	int size = sizeof(land) / sizeof(land[0]) * sizeof(land[0]) / sizeof(land[0][0]);
std::cout<<size;
}
