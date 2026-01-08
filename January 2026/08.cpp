#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // Base case: zero odd numbers seen
        int oddCount = 0, result = 0;

        for (int num : arr) {
            if (num % 2 != 0)
                oddCount++;

            if (freq.find(oddCount - k) != freq.end())
                result += freq[oddCount - k];

            freq[oddCount]++;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 2, 5, 6, 9, 2, 11};
    int k = 2;
    cout << sol.countSubarrays(arr, k) << endl;  // Output: 8
    return 0;
}
