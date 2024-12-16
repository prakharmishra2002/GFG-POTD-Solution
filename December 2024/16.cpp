class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        if (a.size() > b.size()) return kthElement(b, a, k);

        int n = a.size(), m = b.size(), low = max(0, k - m), high = min(k, n);

        while (low <= high) {
            int cut1 = (low + high) / 2, cut2 = k - cut1;
            int l1 = cut1 > 0 ? a[cut1 - 1] : INT_MIN;
            int l2 = cut2 > 0 ? b[cut2 - 1] : INT_MIN;
            int r1 = cut1 < n ? a[cut1] : INT_MAX;
            int r2 = cut2 < m ? b[cut2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) return max(l1, l2);
            (l1 > r2) ? high = cut1 - 1 : low = cut1 + 1;
        }
        return -1;
    }
};
