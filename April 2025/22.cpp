class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int res = 0;
        for (int num : arr) res ^= num;
        return res;
    }
};


2)
class Solution {
  public:
    int findUnique(vector<int> &a) {
        int r = 0;
        for (int x : a) r ^= x;
        return r;
    }
};


3)
class Solution {
  public:
    int findUnique(vector<int> &a) {
        unordered_map<int, int> freq;
        for (int x : a) freq[x]++;
        for (auto it = freq.begin(); it != freq.end(); ++it)
            if (it->second == 1) return it->first;
        return -1;
    }
};


4)
class Solution {
  public:
    int findUnique(vector<int> &a) {
        sort(a.begin(), a.end());
        int i = 0, n = a.size();
        while (i < n - 1) {
            if (a[i] != a[i + 1]) return a[i];
            i += 2;
        }
        return a[n - 1];
    }
};
