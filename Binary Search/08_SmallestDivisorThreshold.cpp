class Solution {
public:
    int calcSum(vector<int>& nums, int divisor){
        int sum = 0;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(nums[i] <= divisor){
                sum++;
            }
            else{
                sum += ceil(double(nums[i]) / double(divisor));
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int size = nums.size();
        if(threshold < size){
            return -1;
        }
        int low = 1;
        int high =  *max_element(nums.begin(),nums.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = calcSum(nums, mid);
            if(sum <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};