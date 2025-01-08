#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to count the number of possible triangles
int countTriangles(int arr[], int n) {
    // Sort the array
    qsort(arr, n, sizeof(int), compare);
    int count = 0;

    // Iterate through the array using three pointers
    for (int i = 0; i < n - 2; i++) {
        int k = i + 2;
        for (int j = i + 1; j < n - 1; j++) {
            while (k < n && arr[i] + arr[j] > arr[k]) {
                k++;
            }
            // Count the number of possible triangles with arr[i] and arr[j]
            if (k > j) {
                count += k - j - 1;
            }
        }
    }

    return count;
}
