class Solution {
public:
    bool isValid(vector<int> weights, int capacity, int days){
        int size = weights.size();
        int remDays = days;
        int i=0;
        int sum = 0;
        for(int i=0; i<size; i++){
            sum += weights[i];
            if(weights[i] > capacity){
                return false;
            }
            if(sum + weights[i] <= capacity){
                sum += weights[i];
            }
            else{
                remDays--;
                sum = weights[i];
                if(remDays == 0){
                    return false;
                }
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while(low <= high){
            int mid = low + (high-low)/2;
            bool check = isValid(weights, mid, days);
            if(check){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};