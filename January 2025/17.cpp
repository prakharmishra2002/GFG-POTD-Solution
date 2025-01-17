class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);

        int left_product = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = left_product;
            left_product *= arr[i];
        }

        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right_product;
            right_product *= arr[i];
        }

        return res;
    }
};
