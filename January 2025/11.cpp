#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }

        int max_len = 0;
        int start = 0;
        unordered_map<char, int> char_index;

        for (int end = 0; end < n; ++end) {
            if (char_index.find(s[end]) != char_index.end()) {
                start = max(start, char_index[s[end]] + 1);
            }
            char_index[s[end]] = end;
            max_len = max(max_len, end - start + 1);
        }

        return max_len;
    }
};
