class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> res;
        for (int l = 0, r = arr.size() - 1, minDiff = INT_MAX; l < r;) {
            int sum = arr[l] + arr[r], diff = abs(target - sum);
            if (diff < minDiff) minDiff = diff, res = {arr[l], arr[r]};
            sum < target ? ++l : --r;
        }
        return res;
    }
};
