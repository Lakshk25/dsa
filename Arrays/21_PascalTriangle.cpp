/* Variation (I) In this case, we are given the row number r and the column number c, and we need to find out the element at position (r,c).
 */

int ncr(int n, int r)
{
    int ans = 1;

    for (int i = 0; i < r; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
}

int pascalElement(int r, int c){
    return ncr(r-1, c-1);
}

/* Variation (II) Given the row number n. Print the n-th row of Pascal’s triangle.
 */

// Naive Approach
int pascalRowNaive(int row){
    for(int col=1; col<=row; col++){
        ncr(row-1, col-1);
    }
}

// Optimal 

vector<int> pascalRow(int row){
    int ans = 1;
    vector<int>ansRow;
    ansRow.push_back(ans);

    for(int col=1; col<row; col++){
        ans = ans * (row-col);
        ans = ans / col;
        ansRow.push_back(ans);
    } 
    return ansRow;
}

/* Variation (III) Print full  Pascal’s triangle.
 */

// naive Approach

vector<vector<int>> pascalTriangleNaive(int n){
    vector<vector<int>>ans;

    for(int row=1; row<=n; row++){
        vector<int>temp;
        for(int col=1; col<=row; col++){
            temp.push_back(ncr(row-1, col-1));
        }
        ans.push_back(temp);
    }
    return ans;
}

// Optimal

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>>ans;

    for(int row=1; row<=n; row++){
        ans.push_back(pascalRow(row));
    }
}