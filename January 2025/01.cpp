class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> umap;

        for (const string& s : arr) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            umap[sorted_s].push_back(s);
        }

        vector<vector<string>> result;
        for (auto it = umap.begin(); it != umap.end(); ++it)
            result.push_back(move(it->second));

        return result;
    }
};