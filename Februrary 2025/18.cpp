class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        nth_element(p.begin(), p.begin() + k, p.end(), [](auto&a, auto&b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
        return {p.begin(), p.begin()+k};
    }
};
