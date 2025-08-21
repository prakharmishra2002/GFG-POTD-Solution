class Solution {
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        // Sort the array to simplify difference calculations
        sort(arr.begin(), arr.end());

        // Helper function to check if a minimum difference is feasible
        auto isPossible = [&](int minDiff) {
            int count = 1;
            int lastSelected = arr[0];

            for (int i = 1; i < arr.size(); ++i) {
                if (arr[i] - lastSelected >= minDiff) {
                    count++;
                    lastSelected = arr[i];
                    if (count == k) return true;
                }
            }
            return false;
        };

        // Binary search for the maximum minimum difference
        int low = 0;
        int high = arr.back() - arr.front();
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
