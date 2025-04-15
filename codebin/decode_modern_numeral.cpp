#include <iostream>
#include <string>

using namespace std
int main(){
	string roman;
	cin>> roman;
	int solution();
	solution(roman);
}
int solution(string roman) {
  int I = 1;
  int V = 5;
  int X = 10;
  int L = 50;
  int C = 100;
  int D = 500;
  int M = 1000;
  int size  = roman.size();
  int decoded_roman = 0;:
  for(int i = 0;i < size; i++){
    if(roman[i] == 'I'){
      if(roman[i+1] != 'V' && roman[i+1] != 'X' && roman[i+1] != 'L' && roman[i+1] != 'C' && roman[i+1] != 'D' && roman[i+1] != 'M'){
      decoded_roman += I;
    }
    else{
      decoded_roman = roman[i+1] - I;
    }
     if(roman[i] == 'V'){
       if(roman[i+1] != 'X' && roman[i+1] != 'L' && roman[i+1] != 'C' && roman[i+1] != 'D' && roman[i+1] != 'M')
      decoded_roman += V;
    }
      else{
        decoded_roman = roman[i+1] - V;
      }
     if(roman[i] == 'X'){
       if(roman[i+1] != 'L' && roman[i+1] != 'C' && roman[i+1] != 'D' && roman[i+1] != 'M')
      decoded_roman += X;
    }
      else{
        decoded_roman = roman[i+1] - X;
      }
     if(roman[i] == 'L'){
       if(roman[i+1] != 'C' && roman[i+1] != 'D' && roman[i+1] != 'M')
      decoded_roman += L;
    }
      else{
        decoded_roman = roman[i+1] - L;
      }
     if(roman[i] == 'C'){
       if(roman[i+1] != 'D' && roman[i+1] != 'M')
      decoded_roman += C;
    }
      else{
        decoded_roman = roman[i+1] - C;
      }
     if(roman[i] == 'D'){
       if(roman[i+1] != 'M')
      decoded_roman += D;
    }
      else{
        decoded_roman = roman[i+1] - D;
      }
     if(roman[i] == 'M'){
      decoded_roman += M;
    } 
}
  return decoded_roman;
  }
  }
