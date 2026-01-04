#include <stdio.h>

// Function to sort array of 0s, 1s, and 2s
void sort012(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            // Swap arr[low] and arr[mid]
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {  // arr[mid] == 2
            // Swap arr[mid] and arr[high]
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            
            high--;
        }
    }
}

// Example usage
int main() {
    int arr[] = {0, 1, 2, 0, 1, 2, 1, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sort012(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    // Output: 0 0 0 1 1 1 2 2 2
    return 0;
}
