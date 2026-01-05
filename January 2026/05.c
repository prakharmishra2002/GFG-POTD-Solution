#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find maximum subarray sum of exact size k
long long maxSubarraySum(int arr[], int n, int k) {
    if (n < k || k <= 0) {
        return 0;
    }
    
    // Compute sum of first window
    long long windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += arr[i];
    }
    
    long long maxSum = windowSum;
    
    // Slide the window across the array
    for (int i = k; i < n; ++i) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }
    
    return maxSum;
}

// Example usage (for testing)
int main() {
    int arr1[] = {100, 200, 300, 400};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;
    printf("%lld\n", maxSubarraySum(arr1, n1, k1));  // Output: 700

    int arr2[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 4;
    printf("%lld\n", maxSubarraySum(arr2, n2, k2));  // Output: 39

    return 0;
}
