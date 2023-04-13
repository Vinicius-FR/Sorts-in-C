#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
   int i, j, temp;
   bool swapped;
   for (i = 0; i < n-1; i++) {
       swapped = false;
       for (j = 0; j < n-i-1; j++) {
           if (arr[j] > arr[j+1]) {
               // swap arr[j] and arr[j+1]
               temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
               swapped = true;
           }
       }
       if (!swapped) {
           // If no elements were swapped, then the array is already sorted
           break;
       }
   }
}

int main() {
   int n;
   printf("Enter the length of the array: ");
   scanf("%d", &n);

   int arr[n];
   
   srand(time(NULL)); // seed random number generator with current time
   //printf("Unsorted array: ");
   for (int i = 0; i < n; i++) {
       arr[i] = rand() % 100; // generate random integer between 0 and 99
       //arr[n-i-1] = i;
       //printf("%d ", arr[i]);
   }
   printf("\n");

   clock_t start = clock(); // start timing
   bubbleSort(arr, n);
   clock_t end = clock(); // end timing
   double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

   //printf("Sorted array: ");
   //for (int i = 0; i < n; i++)
    //   printf("%d ", arr[i]);
   //printf("\n");

   printf("Time taken: %f seconds\n", time_spent);
   return 0;
}