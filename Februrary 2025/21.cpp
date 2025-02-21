#include <stack>
#include <unordered_map>

class Solution {
  public:
    bool isBalanced(std::string& s) {
        std::stack<char> stack;
        std::unordered_map<char, char> bracket_map = {{')', '('}, {'}', '{'}, {']', '['}};
        
        for (char& c : s) {  // Changed variable name from 'char' to 'c'
            if (bracket_map.count(c)) {
                char top_element = stack.empty() ? '#' : stack.top();
                stack.pop();
                if (top_element != bracket_map[c]) {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        
        return stack.empty();
    }
};
