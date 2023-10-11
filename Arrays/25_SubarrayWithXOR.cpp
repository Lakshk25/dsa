// Brute force

int subarraysWithSumK(vector < int > a, int b) {
    int count = 0;
    int n = a.size();
    int check = 0;
    for(int i=0; i<n; i++){
        int check = 0;
        for(int j=i; j<n; j++){
            check = check ^ a[j];
            if(check == b){
                count++;
            }
        }
    }
    return count;
}

// Optimal

#include<unordered_map>
int subarraysWithSumK(vector < int > a, int b) {
    int count = 0;
    int n = a.size();
    unordered_map<int,int>mapping;
    mapping[0] = 1;
    int xorr = 0;
    for(int i=0; i<n; i++){
        xorr = xorr ^ a[i];
        int remain = xorr ^ b;
        count += mapping[remain];
        mapping[xorr]++;
    }
    return count;
}