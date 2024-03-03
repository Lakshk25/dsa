
bool isPossible(vector<int> &stalls, int k , int mid){
    int cows = 1;
    int initialPos = stalls[0];         // first cow position
    for (int i = 0; i < stalls.size(); i++)
    {
        if(stalls[i] - initialPos >= mid){  // check minimum distance so cows not fight
            cows++;
            if(cows == k){          // if all cows placed return
                return true;
            }
            initialPos = stalls[i];        // to  place cow at this postion
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin() , stalls.end());
    int low = 0;
    int high = stalls[stalls.size() - 1];

    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(isPossible(stalls, k, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}