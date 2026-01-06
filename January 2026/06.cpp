#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0 || k == 0 || k > n) return 0;
        
        // Prefix XOR array
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        long long maxXOR = 0;
        for (int i = k - 1; i < n; i++) {
            long long currentXOR = prefix[i + 1] ^ prefix[i + 1 - k];
            maxXOR = max(maxXOR, currentXOR);
        }
        
        return maxXOR;
    }
};
