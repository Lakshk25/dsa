class Solution {
public:
    int countSubArrays(vector<int>& nums, int maxSum){
        int sum = 0;
        int n = nums.size();
        int subArray = 1;
        for(int i=0; i<n; i++){
            if(nums[i] + sum <= maxSum){
                sum += nums[i];
            }
            else{
                subArray++;
                sum = nums[i];
            }
        }
        return subArray;
    }
    int splitArray(vector<int>& nums, int k) {
        int size = nums.size();
        if(size < k){
            return -1;
        }
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while(low <= high){
        int mid = low + (high-low)/2;
        int subArrays = countSubArrays(nums, mid);
        if(subArrays > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
    }
};