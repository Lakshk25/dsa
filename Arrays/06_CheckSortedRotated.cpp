    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[0] < nums[n-1])
    {
        count++;
    }
    if(count <= 1){
        return true;
    }
    return false;   
    }