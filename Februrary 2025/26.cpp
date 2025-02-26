#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;
        
        // Fill left array
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }
        
        // Clear the stack and fill right array
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }
        
        // Array to store maximum of minimums
        vector<int> result(n + 1, 0);
        
        // Fill the result array
        for (int i = 0; i < n; i++) {
            int length = right[i] - left[i] - 1;
            result[length] = max(result[length], arr[i]);
        }
        
        // Fill the rest of the result array
        for (int i = n - 1; i > 0; i--) {
            result[i] = max(result[i], result[i + 1]);
        }
        
        // Exclude the 0th element
        result.erase(result.begin());
        
        return result;
    }
};
