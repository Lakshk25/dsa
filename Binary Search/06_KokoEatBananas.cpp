class Solution {
public:
    long long totalHours(vector<int>& piles, int hourly){
    long long totalH = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++) {
        totalH += (piles[i]/hourly)+(piles[i]%hourly!=0);
    }
    return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high= *max_element(piles.begin(),piles.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            long long hours = totalHours(piles, mid);
            if(hours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};