class Solution {
public:
    void floydWarshall(vector<vector<int>>& d) {
        int n = d.size(), inf = 1e8;
        vector<vector<int>> next(n, vector<int>(n, -1));
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (d[i][k] < inf && d[k][j] < inf && d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        next[i][j] = k;
                    }
    }
};
