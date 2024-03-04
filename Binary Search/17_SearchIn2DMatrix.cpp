bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row  = -1;
        int col = matrix[0].size()-1;
        int low = 0;
        int high = matrix.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[mid][0] <= target && target <= matrix[mid][col]){
                row = mid;
                break;
            }
            else if(target < matrix[mid][0]){
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        } 
        if(row == -1){
            return false;
        }
        low = 0;
        high = matrix[row].size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }