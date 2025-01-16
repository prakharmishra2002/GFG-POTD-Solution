class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> hM;
        int sum = 0, max_len = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += (arr[i] == 0) ? -1 : 1;
            if (sum == 0) max_len = i + 1;
            if (hM.count(sum)) max_len = max(max_len, i - hM[sum]);
            else hM[sum] = i;
        }
        return max_len;
    }
};
