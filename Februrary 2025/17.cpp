class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        nth_element(arr.begin(), arr.end() - k, arr.end());
        partial_sort(arr.end() - k, arr.end(), arr.end(), greater<int>());
        return vector<int>(arr.end() - k, arr.end());
    }
};
