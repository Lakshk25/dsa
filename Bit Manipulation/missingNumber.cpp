#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int missingNumber(vector<int> &nums)
{
    int ans = 0;
    for (int num : nums)
    {
        ans ^= num;
    }
    for (int i = 0; i <= nums.size(); i++)
    {
        ans ^= i;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    cout << missingNumber(arr);
    return 0;
}