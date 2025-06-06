#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        int d = 256;  // Number of characters in the input alphabet
        int q = 101;  // A prime number for hashing
        int m = pat.length();
        int n = txt.length();
        int p = 0;  // Hash value for pattern
        int t = 0;  // Hash value for text
        int h = 1;
        vector<int> result;

        // Compute the value of h as "pow(d, m-1) % q"
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Compute the hash values for pattern and first window of text
        for (int i = 0; i < m; i++) {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // Check if the hash values match
            if (p == t) {
                // If hash matches, check character by character
                if (txt.substr(i, m) == pat)
                    result.push_back(i + 1);  // 1-based indexing
            }

            // Compute hash for the next window
            if (i < n - m) {
                t = (d * (t - txt[i] * h) + txt[i + m]) % q;

                // Convert negative values to positive
                if (t < 0)
                    t += q;
            }
        }

        return result;
    }
};
