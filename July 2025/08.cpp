class Solution {
public:
    vector<int> findGreater(vector<int>& a) {
        unordered_map<int, int> f;
        for (int x : a) f[x]++;
        vector<int> r(a.size(), -1);
        stack<int> s;
        for (int i = 0; i < a.size(); i++) {
            while (!s.empty() && f[a[i]] > f[a[s.top()]]) {
                r[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
        return r;
    }
};
