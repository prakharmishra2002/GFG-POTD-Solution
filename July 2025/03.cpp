class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        if (k == 0 || n == 0) return -1;

        unordered_map<char, int> charFreq;
        int left = 0, maxLen = -1;

        for (int right = 0; right < n; ++right) {
            charFreq[s[right]]++;

            while (charFreq.size() > k) {
                charFreq[s[left]]--;
                if (charFreq[s[left]] == 0) {
                    charFreq.erase(s[left]);
                }
                left++;
            }

            if (charFreq.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};
