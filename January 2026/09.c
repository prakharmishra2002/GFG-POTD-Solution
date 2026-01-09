#include <stdio.h>
#include <string.h>

#define MAX_VAL 100001

int countAtMostK(int arr[], int n, int k) {
    int freq[MAX_VAL] = {0};
    int left = 0, result = 0, distinct = 0;

    for (int right = 0; right < n; ++right) {
        if (freq[arr[right]] == 0)
            distinct++;
        freq[arr[right]]++;

        while (distinct > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0)
                distinct--;
            left++;
        }

        result += right - left + 1;
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 2, 3};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", countAtMostK(arr, n, k));  // Output: 9
    return 0;
}
