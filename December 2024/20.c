void spirallyTraverse(int** mat, int r, int c) {
    int top = 0, left = 0, bottom = r - 1, right = c - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; printf("%d ", mat[top][i++]));
        top++;
        for (int i = top; i <= bottom; printf("%d ", mat[i++][right]));
        right--;
        if (top <= bottom)
            for (int i = right; i >= left; printf("%d ", mat[bottom][i--]));
        bottom--;
        if (left <= right)
            for (int i = bottom; i >= top; printf("%d ", mat[i--][left]));
        left++;
    }
    printf("\n");
}