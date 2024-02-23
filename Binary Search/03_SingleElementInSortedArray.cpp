// Brute Force

int singleNonDuplicate(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }
    return ans;
}

// optimal

int singleNonDuplicate(vector<int> &nums)
{
    int size = nums.size();
    if (nums.size() == 1)
        return nums[0];

    int low = 0;
    int high = nums.size() - 1;

    if (nums[low] != nums[1])
        return nums[0];

    if (nums[high] != nums[high - 1])
        return nums[high];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // current mid element is unique
        if ((mid - 1 >= 0 && nums[mid] != nums[mid - 1]) && (mid + 1 < size && nums[mid] != nums[mid + 1]))
            return nums[mid];

        // if mid is even index
        if (mid % 2 == 0)
        {
            // if duplicate present on next index
            if (mid + 1 < size && nums[mid] == nums[mid + 1])
            {
                low = mid + 1;
            }
            // if present on prev index
            else
            {
                high = mid - 1;
            }
        }
        // if mid is odd
        else
        {
            // if duplicate present on next index
            if (mid + 1 < size && nums[mid] == nums[mid + 1])
            {
                high = mid - 1;
            }
            // if duplicate on prev index
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}