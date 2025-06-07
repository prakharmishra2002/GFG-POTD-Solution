#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        vector<int> diff_arr(n);
        
        // Compute the difference array
        for (int i = 0; i < n; i++)
            diff_arr[i] = a1[i] - a2[i];

        unordered_map<int, int> index_map;  // Stores first occurrence of prefix sum
        int prefix_sum = 0, max_length = 0;

        for (int i = 0; i < n; i++) {
            prefix_sum += diff_arr[i];

            // If the prefix sum is 0, entire subarray from start has equal sum
            if (prefix_sum == 0)
                max_length = i + 1;

            // If prefix sum is already seen, update max_length
            if (index_map.find(prefix_sum) != index_map.end()) {
                max_length = max(max_length, i - index_map[prefix_sum]);
            } else {
                index_map[prefix_sum] = i;  // Store first occurrence
            }
        }

        return max_length;
    }
};
