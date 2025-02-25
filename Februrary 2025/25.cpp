#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaxArea(vector<int> &arr) {
        // Initialize an empty stack and max area
        stack<int> stack;
        int max_area = 0;
        int index = 0;

        while (index < arr.size()) {
            // If this bar is higher than the bar at stack top, push it to the stack
            if (stack.empty() || arr[stack.top()] <= arr[index]) {
                stack.push(index++);
            } else {
                // Pop the top
                int top_of_stack = stack.top();
                stack.pop();
                // Calculate the area with arr[top_of_stack] as the smallest (or minimum height) bar 'h'
                int area = arr[top_of_stack] * (stack.empty() ? index : index - stack.top() - 1);
                // Update max_area, if needed
                max_area = max(max_area, area);
            }
        }

        // Now, pop the remaining bars from stack and calculate area with each popped bar
        while (!stack.empty()) {
            int top_of_stack = stack.top();
            stack.pop();
            int area = arr[top_of_stack] * (stack.empty() ? index : index - stack.top() - 1);
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
