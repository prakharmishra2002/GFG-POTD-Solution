class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> result;
        int top = 0, left = 0, bottom = mat.size() - 1, right = mat[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; result.push_back(mat[top][i++]));
            top++;
            for (int i = top; i <= bottom; result.push_back(mat[i++][right]));
            right--;
            if (top <= bottom)
                for (int i = right; i >= left; result.push_back(mat[bottom][i--]));
            bottom--;
            if (left <= right)
                for (int i = bottom; i >= top; result.push_back(mat[i--][left]));
            left++;
        }
        return result;
    }
};