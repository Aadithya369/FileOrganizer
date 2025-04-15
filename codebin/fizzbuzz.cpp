//fizzbuzz reverse
#include <iostream>
int main(){
	int n;
	std::cin>>n;
	for(int i = n;i > 0;i--){
		if(i%3==0 && i%5==0){
			std::cout<<"fizzbuzz\n";
		}
		else if(i%3 == 0){
			std::cout<<"fizz\n";
		}
		else if(i%5==0){
			std::cout<<"buzz\n";
		}
		else{
			std::cout<<i<<"\n";
		}
	}
}
