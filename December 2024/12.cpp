class Solution {
public:
    int countFreq(const vector<int>& arr, int target) {
        auto lower = lower_bound(arr.begin(), arr.end(), target);
        auto upper = upper_bound(lower, arr.end(), target);
        return (lower != arr.end() && *lower == target) ? (upper - lower) : 0;
    }
};