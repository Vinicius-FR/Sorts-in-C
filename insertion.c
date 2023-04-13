#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    bool sorted = true;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            sorted = false;
        }
        arr[j + 1] = key;
        if (sorted) return; // exit early if already sorted
    }
}

int main2() {
   int n;
   printf("Enter the length of the array: ");
   scanf("%d", &n);

   int arr[n];
   
   //srand(time(NULL)); // seed random number generator with current time
   //printf("Unsorted array: ");
   for (int i = 0; i < n; i++) {
       //arr[i] = rand() % 100; // generate random integer between 0 and 99
       arr[n-i-1] = i;
       //printf("%d ", arr[i]);
   }
   printf("\n");

   clock_t start = clock(); // start timing
   insertionSort(arr, n);
   clock_t end = clock(); // end timing
   double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

   //printf("Sorted array: ");
   //for (int i = 0; i < n; i++)
    //   printf("%d ", arr[i]);
   //printf("\n");

   printf("Time taken: %f seconds\n", time_spent);
   return 0;
}