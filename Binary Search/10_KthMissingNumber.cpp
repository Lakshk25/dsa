class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missNums = 0;

        for(int i=0; i<INT_MAX; i++){
            if(!binary_search(arr.begin(), arr.end(), i)){
                if(missNums == k){
                    return i;
                }
                missNums++;
            }
        }
        return -1;
    }
};