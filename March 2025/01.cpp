class Solution {
public:
    string decodedString(string &s) {
        stack<pair<string, int>> stack;
        string current_string = "";
        int current_num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0');
            } else if (c == '[') {
                stack.push({current_string, current_num});
                current_string = "";
                current_num = 0;
            } else if (c == ']') {
                auto top = stack.top();
                stack.pop();
                string last_string = top.first;
                int num = top.second;
                string temp_string = "";
                for (int i = 0; i < num; ++i) {
                    temp_string += current_string;
                }
                current_string = last_string + temp_string;
            } else {
                current_string += c;
            }
        }

        return current_string;
    }
};
