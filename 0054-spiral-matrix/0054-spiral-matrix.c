int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    int* result = (int*)malloc(sizeof(int) * m * n);
    *returnSize = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; i++)
            result[(*returnSize)++] = matrix[top][i];
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            result[(*returnSize)++] = matrix[i][right];
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[(*returnSize)++] = matrix[bottom][i];
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[(*returnSize)++] = matrix[i][left];
            left++;
        }
    }

    return result;
}
