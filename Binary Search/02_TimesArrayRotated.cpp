int findKRotation(vector<int> &arr){
        int ans = INT_MAX;
        int high = arr.size() - 1;
        int index = -1;
        int low = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[low] <= arr[mid]){
                if(ans > arr[low]){
                    ans = arr[low];
                    index = low;
                }
                low = mid + 1;
            }
            else{
                if(ans > arr[mid]){
                    ans = arr[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
}