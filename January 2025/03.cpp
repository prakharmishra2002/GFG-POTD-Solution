class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        long res = 0, prefXOR = 0;
        unordered_map<int, int> mp;
        for (int val : arr) {
            prefXOR ^= val;
            res += mp[prefXOR ^ k] + (prefXOR == k);
            mp[prefXOR]++;
        }
        return res;
    }
};
