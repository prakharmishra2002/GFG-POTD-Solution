#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // Initialize a stack and a vector to store the spans
        stack<int> s;
        vector<int> span(arr.size(), 0);

        // Iterate through the list of prices
        for (int i = 0; i < arr.size(); i++) {
            // While stack is not empty and the current price is greater than
            // the price at the index stored at the top of the stack
            while (!s.empty() && arr[i] >= arr[s.top()]) {
                s.pop();
            }
            // If stack is empty, it means the current price is greater than all previous prices
            if (s.empty()) {
                span[i] = i + 1;
            } else {
                // Calculate the span by subtracting the index of the last higher price from the current index
                span[i] = i - s.top();
            }
            // Push the current index to the stack
            s.push(i);
        }

        return span;
    }
};
