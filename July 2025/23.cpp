class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        long long totalSum = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            totalSum += static_cast<long long>(arr[i]) * (i + 1) * (n - i);
        }
        return static_cast<int>(totalSum);
    }
};
