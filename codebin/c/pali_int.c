#include <stdio.h>
#include <stdbool.h>

// Function prototype
bool isPalindrome(int x);

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (isPalindrome(x)) {
        printf("%d is a palindrome.\n", x);
    } else {
        printf("%d is not a palindrome.\n", x);
    }

    return 0;
}

bool isPalindrome(int x) {
    int original = x;
    int reversed = 0;

    // Negative numbers are not considered palindromes
    if (x < 0) return false;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}
