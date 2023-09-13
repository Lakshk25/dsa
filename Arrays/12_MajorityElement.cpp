    // ********************* Boyer-Moore Majority Vote Algorithm applied **********************
    
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            if(count == 0)
                element = nums[i];
            
            if(element == nums[i])
                count++;
            else
                count--;
        }
        return element;
    }