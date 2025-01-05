class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1, ans = 0;
        while (l < r) (arr[l] + arr[r] < target) ? ans += (r - l), l++ : r--;
        return ans;
    }
};