#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countAtMostK(vector<int>& arr, int k) {
        int left = 0, result = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < arr.size(); ++right) {
            freq[arr[right]]++;

            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0)
                    freq.erase(arr[left]);
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2, 3};
    int k = 2;
    cout << sol.countAtMostK(arr, k) << endl;  // Output: 9
    return 0;
}
