class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount = {{0, 1}};
        int sum = 0, count = 0;

        for (int num : arr) {
            sum += num;
            count += prefixSumCount[sum - k];
            prefixSumCount[sum]++;
        }

        return count;
    }
};