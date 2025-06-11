#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<pair<int, int>> st;  // Stack to track remaining balls (color, radius)

        for (size_t i = 0; i < color.size(); i++) {
            // If stack is not empty and top element matches current color & radius, remove it
            if (!st.empty() && st.top() == make_pair(color[i], radius[i])) {
                st.pop();
            } else {
                st.push(make_pair(color[i], radius[i]));
            }
        }

        return st.size();  // Remaining balls count
    }
};
