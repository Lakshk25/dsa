// ********** TC O(nlogn) **************** SC O(1) ********************* 
    
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int sum = 0;
        int i = 0;
        int j = nums.size()-1;
        
        while(i < j){
            sum = nums[i] + nums[j];
            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }


// *********** TC (n * logn) **************** SC O(n) ********************* 


    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mapping;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            mapping[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(mapping.find(diff) != mapping.end()){
                if(mapping[diff] != i){
                    ans.push_back(i);
                    ans.push_back(mapping[diff]);
                    return ans;
                };
            }
        }
    return ans;
    }