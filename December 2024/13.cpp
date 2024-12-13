class Solution {
public:
    int findMin(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            if (arr[lo] < arr[hi])
                return arr[lo];
            int mid = lo + ((hi - lo) >> 1); 
            if (arr[mid] > arr[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        return arr[lo];
    }
};