#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long maxSubarrayXOR(int* arr, int n, int k) {
    if (n == 0 || k == 0 || k > n) return 0;
    
    // Allocate prefix XOR array
    long long* prefix = (long long*)malloc((n + 1) * sizeof(long long));
    if (prefix == NULL) return 0; // Memory allocation failed
    
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    
    long long maxXOR = 0;
    for (int i = k - 1; i < n; i++) {
        long long currentXOR = prefix[i + 1] ^ prefix[i + 1 - k];
        if (currentXOR > maxXOR) {
            maxXOR = currentXOR;
        }
    }
    
    free(prefix);
    return maxXOR;
}

// Example usage (for testing)
/*
int main() {
    int arr1[] = {2, 5, 8, 1, 1, 3};
    int n1 = 6, k1 = 3;
    printf("%lld\n", maxSubarrayXOR(arr1, n1, k1)); // Expected: 15
    
    int arr2[] = {1, 2, 4, 5, 6};
    int n2 = 5, k2 = 2;
    printf("%lld\n", maxSubarrayXOR(arr2, n2, k2)); // Expected: 6
    
    return 0;
}
*/
