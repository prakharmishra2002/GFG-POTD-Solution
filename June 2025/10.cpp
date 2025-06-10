#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStrings(string &s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        int n = s.size();
        int total_swaps = (n * (n - 1)) / 2; // All possible index swaps

        // Count duplicate swaps where characters are identical
        int duplicate_count = 0;
        for (auto &entry : freq) {
            int val = entry.second;
            duplicate_count += (val * (val - 1)) / 2;
        }

        return total_swaps - duplicate_count + (duplicate_count > 0 ? 1 : 0);
    }
};
