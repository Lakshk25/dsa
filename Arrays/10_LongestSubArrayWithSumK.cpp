#include <iostream>
using namespace std;

// SOLUTION FOR BOTH POSITIVES AND NEGATIVES

int lenOfLongSubarr(int A[], int N, int K)
{
    map<int, int> preSum;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum == K)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - K;
        if (preSum.find(rem) != preSum.end())
        {
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }
        // condition for negative and zeros
        if (preSum.find(sum) == preSum.end())
        {
            preSum[sum] = i;
        }
    }
    return maxLen;
}

// OPTIMAL SOLUTION FOR POSITIVES ONLY

int lenOfLongSubarr(int A[], int N, int K)
{
    int sum = 0;
    int size = 0;
    int prev = 0;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        count++;
        if (sum >= K)
        {
            if (sum == K)
            {
                size = max(size, count);
                sum = sum - A[prev++];
                count--;
            }
            while (sum > K)
            {
                sum = sum - A[prev++];
            }
        }
    }
    return size;
}
int main()
{

    return 0;
}