  class Solution:
    def floodFill(self, image, sr, sc, newColor):
        # Get the initial color of the starting pixel
        initialColor = image[sr][sc]
        # If the initial color is the same as the new color, no need to proceed
        if initialColor == newColor:
            return image
        
        # Helper function for DFS
        def dfs(x, y):
            # Check boundary conditions and if the color matches the initial color
            if x < 0 or x >= len(image) or y < 0 or y >= len(image[0]) or image[x][y] != initialColor:
                return
            # Update the color of the current pixel
            image[x][y] = newColor
            # Recursively call DFS for adjacent pixels
            dfs(x + 1, y)  # Down
            dfs(x - 1, y)  # Up
            dfs(x, y + 1)  # Right
            dfs(x, y - 1)  # Left

        # Start the flood fill from the given coordinates
        dfs(sr, sc)
        return image
