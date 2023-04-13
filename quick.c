#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = MAX_SIZE;

    // printf("Enter the size of the array: ");
    // scanf("%d", &n);

    int* arr = (int*) calloc(n, sizeof(int));

    // Fill array with random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        //arr[i] = rand() % n;
        arr[n-i-1] = i;
    }

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Sorted array in %f seconds\n", time_taken);

    return 0;
}
