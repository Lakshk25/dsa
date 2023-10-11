// *********************** Better *************************
//  TC O(n) SC O(n)

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
   int n = arr.size();
    if (n == 0) return 0;

    //sort the array:
    sort(arr.begin(), arr.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (arr[i] - 1 == lastSmaller) {
            //arr[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = arr[i];
        }
        else if (arr[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

    }
};



// *********************** Optimal *************************
//  TC O(n) SC O(n)


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int mapping[100000] = {0};
        int maxLen = 0;
        
        for(int i=0; i<N; i++){
            int value = arr[i];
            mapping[value] = 1;
            maxLen = max(maxLen, arr[i]);
        }
        
        int count = 0;
        int maxCount = 0;
        
        for(int i=0; i<=maxLen; i++){
            if(mapping[i] == 1){
                count++;
            }
            else{
                count = 0;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
