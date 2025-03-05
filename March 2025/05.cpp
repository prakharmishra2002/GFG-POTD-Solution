#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int longestStringChain(std::vector<std::string>& words) {
        // Sort the words based on their length
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
        
        // Unordered map to keep track of the longest chain ending with each word
        std::unordered_map<std::string, int> dp;
        
        int max_chain_length = 1;
        
        for (const std::string& word : words) {
            dp[word] = 1;  // Every word can be a chain of at least length 1 (itself)
            
            // Check all possible predecessor words by removing one character
            for (size_t i = 0; i < word.length(); ++i) {
                std::string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = std::max(dp[word], dp[predecessor] + 1);
                }
            }
            
            // Update the max chain length
            max_chain_length = std::max(max_chain_length, dp[word]);
        }
        
        return max_chain_length;
    }
};
