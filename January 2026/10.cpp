#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int atMostK(const string& s, int k) {
        int left = 0, result = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }

    int countSubstr(const string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main() {
    Solution sol;
    string s = "aba";
    int k = 2;
    cout << sol.countSubstr(s, k) << endl;  // Output: 3
    return 0;
}
