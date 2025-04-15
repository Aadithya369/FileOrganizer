#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);  // Convert the first argument to an integer
    int num2 = atoi(argv[2]);  // Convert the second argument to an integer

    int sum = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    return 0;
}

