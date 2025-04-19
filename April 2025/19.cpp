  #include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2]; // Each node has 2 children: 0 and 1
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:
    int maxXor(vector<int> &arr) {
        // Helper function to insert a number into the Trie
        auto insert = [](TrieNode* root, int num) {
            TrieNode* node = root;
            for (int i = 31; i >= 0; --i) { // Iterate over 32 bits (assuming 32-bit integers)
                int bit = (num >> i) & 1;
                if (!node->children[bit]) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];
            }
        };

        // Helper function to find maximum XOR for a number
        auto findMaxXor = [](TrieNode* root, int num) {
            TrieNode* node = root;
            int maxXor = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                int oppositeBit = 1 - bit;
                if (node->children[oppositeBit]) { // Try to take the opposite bit if possible
                    maxXor = (maxXor << 1) | 1;
                    node = node->children[oppositeBit];
                } else { // Otherwise, take the current bit
                    maxXor = maxXor << 1;
                    node = node->children[bit];
                }
            }
            return maxXor;
        };

        // Build Trie and calculate maximum XOR
        TrieNode* root = new TrieNode();
        int maxResult = 0;

        // Insert the first number into the Trie
        insert(root, arr[0]);

        for (int i = 1; i < arr.size(); ++i) {
            // Find maximum XOR for the current number
            maxResult = max(maxResult, findMaxXor(root, arr[i]));
            // Insert the current number into the Trie
            insert(root, arr[i]);
        }

        return maxResult;
    }
};
