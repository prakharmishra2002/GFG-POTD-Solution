#include <stdio.h>
#include <string.h>

int atMostK(const char* s, int k) {
    int freq[26] = {0};  // Only lowercase letters
    int left = 0, result = 0, distinct = 0;
    int n = strlen(s);

    for (int right = 0; right < n; ++right) {
        int idx = s[right] - 'a';
        if (freq[idx] == 0)
            distinct++;
        freq[idx]++;

        while (distinct > k) {
            int lidx = s[left] - 'a';
            freq[lidx]--;
            if (freq[lidx] == 0)
                distinct--;
            left++;
        }

        result += right - left + 1;
    }

    return result;
}

int countSubstr(const char* s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}

int main() {
    const char* s = "aba";
    int k = 2;
    printf("%d\n", countSubstr(s, k));  // Output: 3
    return 0;
}
