#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        vector<int> result;

        // Initialize first window
        for (int i = 0; i < k; ++i)
            freq[arr[i]]++;

        result.push_back(freq.size());

        // Slide the window
        for (int i = k; i < arr.size(); ++i) {
            // Remove outgoing element
            int out = arr[i - k];
            freq[out]--;
            if (freq[out] == 0)
                freq.erase(out);

            // Add incoming element
            freq[arr[i]]++;

            result.push_back(freq.size());
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    vector<int> res = sol.countDistinct(arr, k);
    for (int val : res)
        cout << val << " ";
    return 0;
}
