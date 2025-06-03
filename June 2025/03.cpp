#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int atMostK(string& s, int k) {
        unordered_map<char, int> freq;
        int left = 0, total = 0;

        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            total += right - left + 1;
        }

        return total;
    }

    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};
