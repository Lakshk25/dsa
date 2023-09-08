#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>nums = {3,0,1};
    int ans = 0;
    for (int num : nums)
    {
        cout<<num<<" XOR "<<ans;
        ans ^= num;
        cout<<" = "<<ans<<endl;
    }
    cout<<"*****"<<endl;
    for (int i = 0; i <= nums.size(); i++)
    {

        cout<<i<<" XOR "<<ans;
        ans ^= i;
        cout<<" = "<<ans<<endl;
    }
    cout<<ans;
}