class Solution {
public:
    void nextPermutation(vector<int>& nums) {
                int n = nums.size(); // Get the size of the 'nums' vector
        int index = -1; // Initialize 'index' to -1

        // 1. Find the first element 'index' from the right such that nums[i] < nums[i+1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // 2. If 'index' is found, find the smallest element greater than nums[index] from the right
        if (index != -1) {
            for (int i = n - 1; i >= index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]); // Swap nums[i] and nums[index]
                    break;
                }
            }
        }

        // 3. Reverse the elements to the right of 'index'
        reverse(nums.begin() + index + 1, nums.end());
    }
};