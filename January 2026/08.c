#include <stdio.h>

#define MAXN 100005

int countSubarrays(int arr[], int n, int k) {
    int freq[MAXN] = {0};
    freq[0] = 1;  // Base case
    int oddCount = 0, result = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 != 0)
            oddCount++;

        if (oddCount >= k)
            result += freq[oddCount - k];

        freq[oddCount]++;
    }

    return result;
}

int main() {
    int arr[] = {2, 2, 5, 6, 9, 2, 11};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", countSubarrays(arr, n, k));  // Output: 8
    return 0;
}
