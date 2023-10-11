#include <bits/stdc++.h>
using namespace std;

// ************************* KADANE ALGO ************************

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum < nums[i])
        {
            sum = nums[i];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int maxSubArrayIndex(vector<int> &nums)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int start = 0;
    int end = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum < nums[i])
        {
            start = i;
            sum = nums[i];
        }
        if(maxSum < sum)
            end = i;
        maxSum = max(maxSum, sum);
    }

        cout << "The subarray is: [";
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << "]n";
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubArray(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    maxSubArrayIndex(arr);
    return 0;
}