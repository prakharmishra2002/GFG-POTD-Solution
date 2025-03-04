class Solution {
public:
    int lis(std::vector<int>& arr) {
        std::vector<int> ans;
        for (int num : arr) {
            auto it = std::lower_bound(ans.begin(), ans.end(), num);
            if (it == ans.end()) ans.push_back(num);
            else *it = num;
        }
        return ans.size();
    }
};
