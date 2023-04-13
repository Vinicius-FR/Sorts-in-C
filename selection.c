#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    bool already_sorted = false; // flag to indicate if the array is already sorted
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        if (arr[i] > arr[i+1]) { // if elements are not in sorted order, set the flag to false
            already_sorted = true;
        } else if (already_sorted) { // if the array is already sorted, break the loop
            break;
        }
    }
}

int main() {
   int n;
   printf("Enter the length of the array for: ");
   scanf("%d", &n);

   int arr[n];
   
   //srand(time(NULL)); // seed random number generator with current time
   //printf("Unsorted array: ");
   for (int i = 0; i < n; i++) {
       arr[i] = rand() % 100; // generate random integer between 0 and 99
       //arr[i] = i;
       //printf("%d ", arr[i]);
   }
   printf("\n");

   clock_t start = clock(); // start timing
   selectionSort(arr, n);
   clock_t end = clock(); // end timing
   double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

   //printf("Sorted array: ");
   //for (int i = 0; i < n; i++)
    //   printf("%d ", arr[i]);
   //printf("\n");

   printf("Time taken: %f seconds\n", time_spent);
   return 0;
}