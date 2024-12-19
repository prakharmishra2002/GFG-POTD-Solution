int kthMissing(int* arr, int n, int k) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] - (mid + 1) < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo + k;
}