class Solution {
public:
    int minValue(string &s, int k) {
        int f[26] = {}, m = 0;
        for (char c : s) m = max(m, ++f[c - 'a']);
        vector<int> b(m + 1);
        for (int x : f) if (x) b[x]++;
        while (k && m) {
            if (b[m] <= k) k -= b[m], b[m - 1] += b[m], b[m--] = 0;
            else b[m] -= k, b[m - 1] += k, k = 0;
        }
        int r = 0;
        for (int i = 1; i <= m; i++) r += i * i * b[i];
        return r;
    }
};
