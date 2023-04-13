#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int size) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    merge(arr, left, mid, right, size - mid);
}

int main() {
    int* arr = (int*) calloc(MAX_SIZE, sizeof(int));
    int size = MAX_SIZE;

    // printf("Enter the size of the array: ");
    // scanf("%d", &size);

    // Generate random numbers for the array
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    printf("não morri ainda 1");

    // Check if the array is already sorted
    // int sorted = 1;
    // for (int i = 1; i < size; i++) {
    //     if (arr[i] < arr[i - 1]) {
    //         sorted = 0;
    //         break;
    //     }
    // }

    // if (sorted) {
    //     printf("Array is already sorted\n");
    //     return 0;
    //}

    clock_t start = clock();
    printf("não morri ainda 2");
    merge_sort(arr, size);
    printf("morri");
    clock_t end = clock();

    // printf("Sorted array: ");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    printf("\n");

    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Merge sort took %f seconds to execute \n", time_taken);
    return 0;
}
