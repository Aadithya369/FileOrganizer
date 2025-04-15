#define typeof(x) __typeof__(x)
#include<stdio.h>
int main() {
    int x = 5;
    typeof(x) y = 10; // y is of the same type as x (int)
    printf("%d\n", y);
    return 0;
}

