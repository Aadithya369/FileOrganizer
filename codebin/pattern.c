#include <stdio.h>

int main (){

    int res;

    printf("\nHow many lines do you wanna create for the pattern? ");
    scanf("%d", &res);

    for(int i = 1; i <= res; i++){
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}