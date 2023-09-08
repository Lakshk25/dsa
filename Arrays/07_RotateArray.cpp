void rotate(vector<int> &nums, int k)
{
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void rotate(vector<int> &nums, int k)
{
    int size = nums.size();
    vector<int> temp = nums;
    for (int i = 0; i < size; i++)
    {
        temp[(i + k) % size] = nums[i];
    }
    nums = temp;
}