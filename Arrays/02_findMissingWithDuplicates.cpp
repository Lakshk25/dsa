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

int main()
{
    vector<int> arr = {1, 3, 3, 3, 4};

    // Approach 1 using sorting and swaping

    // int i=0;
    // while(i<arr.size()){
    //     int index = arr[i] - 1;
    //     if(arr[i] != arr[index]){
    //         swap(arr[i], arr[index]);
    //     }
    //     else{
    //         i++;
    //     }
    // }

    // Approch 2 using visited

    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i]);
        if (arr[index - 1] > 0)
        {
            arr[index - 1] *= -1;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > 0){
            cout<<i+1<<" ";
        }
    }
    
    // printArr(arr);
    // for(int i=0; i<arr.size(); i++){
    //     if(i != arr[i]-1){
    //         cout<<i+1<<" ";
    //     }
    // }
    return 0;
}