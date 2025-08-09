#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int getLongestPrefix(string &s) {
        int n = s.length();
        if (n == 0) 
            return -1;

        // Build LPS (longest proper prefix which is also suffix) array
        vector<int> lps(n, 0);
        int len = 0;   // length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // fallback in the prefix table
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int longest = lps[n - 1];
        // if no proper prefix-suffix or not periodic, return -1
        if (longest == 0) 
            return -1;

        // Check periodicity: total length divisible by the smallest repeating unit
        int unitLen = n - longest;
        if (n % unitLen == 0)
            return longest;
        else
            return -1;
    }
};
