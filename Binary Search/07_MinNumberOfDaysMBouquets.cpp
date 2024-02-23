class Solution {
public:
    int bouquets(vector<int>& bloomDay, int days, int required){
        int totalB = 0;
        int size = bloomDay.size();
        int flowers = 0;

        for(int i=0; i<size; i++){
            if(bloomDay[i] <= days){
                flowers++;
                if(flowers == required){
                    totalB++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }
        return totalB;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        long int flowersReq = static_cast<long long>(k) * m;
        if(size < flowersReq){
            return -1;
        }
        int low = 1;
        int high =  *max_element(bloomDay.begin(),bloomDay.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            int ans = bouquets(bloomDay, mid, k);
            if(ans >= m){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};