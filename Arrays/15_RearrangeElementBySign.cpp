    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;

        int pIndex = 0;
        int nIndex = 0;
        int index = 0;

        while(index < nums.size()){
            while(pIndex < nums.size() && nums[pIndex] < 0)
                pIndex++;
            
            while(nIndex < nums.size() && nums[nIndex] > 0)
                nIndex++;

            if(index % 2 == 0)
                ans.push_back(nums[pIndex++]);
            else
                ans.push_back(nums[nIndex++]);
            index++;
        }
        return ans;
    }