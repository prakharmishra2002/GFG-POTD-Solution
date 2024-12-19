class Solution {
public:
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1; 
        int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0);
        while (low < high) {
            int mid = (low + high) / 2, students = 1, sum = 0;
            for (int pages : arr) {
                if ((sum += pages) > mid) students++, sum = pages;
            }
            if (students > k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};