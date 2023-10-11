// also optimal if we can modify original array
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    vector<int>ans;
    int size = a.size();
    for(int i=0; i<size; i++){
        int index = abs(a[i]) - 1;
        if(a[index] < 0){
            ans.push_back(abs(a[i]));
        }
        else
            a[index] = a[index] * -1;
    }
    for(int i=0; i<size; i++){
        if(a[i] > 0){
            ans.push_back({i + 1});
            break;
        }
    }
    return ans;
}


// optimal

    vector<int> findTwoElement(vector<int> arr, int n) {
        long long N = n;
        long long  S = 0; // array sum
        long long  Sn = (N * (N+1))/2; // sum 1 to n
        long long  S2 = 0; // array square sum
        long long  S2n = (N * (N+1)*(2*N+1)/6); // 1 to n square sum
        
        for(int i=0; i<N; i++){
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];
        }
        
        // x - y = S - Sn => x - y = eq1
        long long eq1 = S - Sn;
        // x + y  = (S2 - S2n)/eq1 => x+y = (S2n - S2n)/x-y
        long long eq2 = (S2 - S2n)/eq1;
        // x = x + y + x - y => x = (eq2 - eq1)/2
        int duplicate = (eq1 + eq2)/2;
        // y = eq2 - x
        int missing = eq2 - duplicate;
        vector<int>ans = {duplicate, missing};
        return ans;
    }