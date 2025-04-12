class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Get the initial color of the starting pixel
        int initialColor = image[sr][sc];
        // If the initial color is the same as the new color, no need to proceed
        if (initialColor == newColor) {
            return image;
        }

        // Helper function for DFS
        auto dfs = [&](int x, int y, auto& dfsRef) -> void {
            // Check boundary conditions and if the color matches the initial color
            if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != initialColor) {
                return;
            }
            // Update the color of the current pixel
            image[x][y] = newColor;
            // Recursively call DFS for adjacent pixels
            dfsRef(x + 1, y, dfsRef); // Down
            dfsRef(x - 1, y, dfsRef); // Up
            dfsRef(x, y + 1, dfsRef); // Right
            dfsRef(x, y - 1, dfsRef); // Left
        };

        // Start the flood fill from the given coordinates
        dfs(sr, sc, dfs);
        return image;
    }
};
