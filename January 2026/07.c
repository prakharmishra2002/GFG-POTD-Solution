#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 100001

void countDistinct(int arr[], int n, int k) {
    int freq[MAX_VAL] = {0};
    int distinct = 0;

    // First window
    for (int i = 0; i < k; ++i) {
        if (freq[arr[i]] == 0)
            distinct++;
        freq[arr[i]]++;
    }
    printf("%d ", distinct);

    // Slide window
    for (int i = k; i < n; ++i) {
        // Remove outgoing
        if (--freq[arr[i - k]] == 0)
            distinct--;

        // Add incoming
        if (freq[arr[i]] == 0)
            distinct++;
        freq[arr[i]]++;

        printf("%d ", distinct);
    }
}

int main() {
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    countDistinct(arr, n, k);
    return 0;
}
