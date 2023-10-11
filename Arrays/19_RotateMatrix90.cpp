// ***************************** BRUTE FORCE ********************
// ********************** TC O(n^2) SC O(n^2) ***************************

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> ans = matrix;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int c = col - 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans[j][c - i] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};

// ***************************** OPTIMAL ********************
// ********************** TC O(n^2) SC O(1) ***************************

/*
*************** for rotating 90 take transpose then swap columns    ***********
*************** for rotating 180 swap columns then swap rows    ***********
*************** for rotating 270 take transpose then swap rows    ***********
*/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int size = matrix.size();

        // take transpose of matrix
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // for rotating 90 swap columns (0 -> size-1 , 1->size-2 ...)
        for (int i = 0; i < size; i++)
        {
            int start = 0;
            int end = size - 1;
            while (start < end)
            {
                swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }

        // ****************** same but reverse row (90) ****************8
        // reversing each row of the matrix
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // for rotating 180 swap rows (DONT TAKE TRANSPOSE ONLY SWAP ROWS AND COLUMNS) (0 -> size-1 , 1->size-2 ...)
        for (int i = 0; i < size; i++)
        {
            int start = 0;
            int end = size - 1;
            while (start < end)
            {
                swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }

        // for rotating 270 swap rows (0 -> size-1 , 1->size-2 ...)
        for (int i = 0; i < size; i++)
        {
            int start = 0;
            int end = size - 1;
            while (start < end)
            {
                swap(matrix[start][i], matrix[end][i]);
                start++;
                end--;
            }
        }
    }
};