class Solution {
public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        int lo = 0, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > arr[mid + 1]) {
                hi = mid; 
            } else {
                lo = mid + 1; 
            }
        }
        return lo; 
    }
};