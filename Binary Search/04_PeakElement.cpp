    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
            return 0;
        
        // if nums[0] is peak
        if(nums[0] > nums[1])
            return 0;
        
        // if last elem is peak
        if(nums[size-1] > nums[size-2])
            return size-1;
        
        // remove 0 and size - 1 elem
        int low = 1;
        int high = size - 2;
        while(low <= high){
            int mid = low + (high-low)/2;
            // peak element
            if((nums[mid] > nums[mid+1]) && (nums[mid] > nums[mid-1])){
                return mid;
            }
            // left part is sorted
            else if(nums[mid] > nums[mid-1]){
                low = mid + 1;
            }
            // right is sorted in descending order
            else{
                high = mid - 1;
            }
        }
        return -1;
    }