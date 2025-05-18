#include <stdio.h>
#include <stdlib.h>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2) {
    int totalSize = size1 + size2;
    int *temp = malloc(totalSize * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Merge step: merge arr1 and arr2 into temp
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            temp[k++] = arr1[i++];
        } else {
            temp[k++] = arr2[j++];
        }
    }
    // Copy remaining elements from arr1, if any
    while (i < size1) {
        temp[k++] = arr1[i++];
    }
    // Copy remaining elements from arr2, if any
    while (j < size2) {
        temp[k++] = arr2[j++];
    }

    // Copy back first size1 elements to arr1
    for (int x = 0; x < size1; x++) {
        arr1[x] = temp[x];
    }
    // Copy remaining elements to arr2
    for (int x = 0; x < size2; x++) {
        arr2[x] = temp[size1 + x];
    }

    free(temp);
}

int main() {
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeSortedArrays(arr1, size1, arr2, size2);

    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}

