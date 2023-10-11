

ONLY WORKS IF MATRIX DOES NOT CONTAINS NEGATIVES
********************** TC O(n^3) ****************************
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    int r = 0;
                    while(r < row){
                        if(matrix[r][j] != 0)
                            matrix[r][j] = -1;
                        r++;
                    }
                    int c = 0;
                    while(c < col){
                        if(matrix[i][c] != 0)
                            matrix[i][c] = -1;
                        c++;
                    }
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

************************** BETTER ********************************8
*************************** TC O(N^2) SC O(N) **********************************
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
         vector<int>rMap(row,0); // row array
        vector<int>cMap(col,0); // col array

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    rMap[i] = 1;
                    cMap[j] = 1;
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(rMap[i]== 1 || cMap[j] == 1)
                    matrix[i][j] = 0;
            }
        }
    }
};

********************** BEST ************************************
********************** TC O(n^2) SC O(1) ****************************

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    // mark i-th row
                    matrix[i][0] = 0;
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // mark with 0 from (1,1) to (row-1, col-1)
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j=0; j<col; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i=0; i<row; i++){
                matrix[i][0] = 0;
            }
        }
    }
};