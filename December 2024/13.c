int findMin(int* arr, int n) {
    int lo = 0, hi = n - 1;
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