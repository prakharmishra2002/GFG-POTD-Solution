#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        vector<pair<int, int>> diff; 
        
        // Compute absolute differences while excluding x
        for (int num : arr) {
            if (num != x) {
                diff.push_back({abs(num - x), -num}); // Use -num for prioritizing larger values
            }
        }

        // Sort based on absolute difference, and prioritize larger numbers in case of a tie
        sort(diff.begin(), diff.end());

        vector<int> result;
        for (int i = 0; i < k && i < diff.size(); i++) {
            result.push_back(-diff[i].second); // Restore original number
        }

        return result;
    }
};
