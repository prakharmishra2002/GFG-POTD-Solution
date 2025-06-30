class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();

        auto canReach = [&](int target) {
            vector<int> diff(n + 1, 0);
            int water = 0, curr_add = 0;

            for (int i = 0; i < n; ++i) {
                curr_add += diff[i];
                int effective_height = arr[i] + curr_add;

                if (effective_height < target) {
                    int needed = target - effective_height;
                    water += needed;
                    if (water > k) return false;

                    curr_add += needed;
                    if (i + w < n + 1)
                        diff[i + w] -= needed;
                }
            }
            return true;
        };

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end()) + k;
        int ans = low;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canReach(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
