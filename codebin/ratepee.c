#include <stdio.h>
int main(){
    FILE *file = fopen("example.txt","r");
    if (file == NULL){
        printf("Error:could not open file.\n");
    }

    

}
