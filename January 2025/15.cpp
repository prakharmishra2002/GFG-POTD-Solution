class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum == k) res = i + 1;
            if (mp.count(sum - k)) res = max(res, i - mp[sum - k]);
            if (!mp.count(sum)) mp[sum] = i;
        }
        return res;
    }
};
