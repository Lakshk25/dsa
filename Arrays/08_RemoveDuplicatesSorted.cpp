    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while(i < nums.size()){
            if(nums[i] != nums[j]){
                j++;
                swap(nums[i], nums[j]);
            }
            i++;
        }
        return j+1;
    }