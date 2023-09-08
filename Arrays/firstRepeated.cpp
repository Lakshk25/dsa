#include<iostream>
#include<vector>
using namespace std;
void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int firstRepeated(vector<int> arr, int n) {
    int arr[2][n] = {{1,2}, {1,2}};

    return 1;
}
int main(){
    vector<int>arr = {1, 5, 3, 4, 3, 5, 6};
    cout<<firstRepeated(arr, arr.size());
}