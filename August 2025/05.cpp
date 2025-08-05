class Solution {
  public:
    bool isPalinSent(string &s) {
        string cleaned;
        
        // Filter out non-alphanumeric and convert to lowercase
        for (char ch : s) {
            if (isalnum(ch)) {
                cleaned += tolower(ch);
            }
        }

        // Check if the cleaned string is a palindrome
        int left = 0, right = cleaned.size() - 1;
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};
