vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result; // Initialize the result vector to store the spiral order elements
    int rowCount = matrix.size(); // Number of rows in the matrix
    int colCount = matrix[0].size(); // Number of columns in the matrix
    int totalCount = rowCount * colCount; // Total number of elements in the matrix
    int top = 0, bottom = rowCount - 1, left = 0, right = colCount - 1; // Define boundaries

    while (result.size() < totalCount) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right && result.size() < totalCount; i++) {
            result.push_back(matrix[top][i]);
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom along the rightmost column
        for (int i = top; i <= bottom && result.size() < totalCount; i++) {
            result.push_back(matrix[i][right]);
        }
        right--; // Move the right boundary to the left

        // Traverse from right to left along the bottom row
        for (int i = right; i >= left && result.size() < totalCount; i--) {
            result.push_back(matrix[bottom][i]);
        }
        bottom--; // Move the bottom boundary up

        // Traverse from bottom to top along the leftmost column
        for (int i = bottom; i >= top && result.size() < totalCount; i--) {
            result.push_back(matrix[i][left]);
        }
        left++; // Move the left boundary to the right
    }
    
    return result;
}
