    

    // if no duplicates are present
    int search(int A[], int l, int h, int key){
        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(A[mid] == key)
                return mid;
            // left sorted
            else if(A[mid] >= A[l]){
                // key present in left sorted part
                if(A[l] <= key && key <= A[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            // right sorted
            else{
                // key present in right sorted part
                if(A[mid] <= key && A[h] >= key)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return ans;
    }


// edge if duplicates are present
    bool search(vector<int>& nums, int target) {
        int l = 0 , h = nums.size() - 1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target)
                return true;
            // edge case
            if(nums[l] == nums[mid] && nums[h] == nums[mid]){
                l = l + 1;
                h = h - 1;
                continue;
            }
            // left sorted
            if(nums[mid] >= nums[l]){
                // target present in left sorted part
                if(nums[l] <= target && target <= nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            // right sorted
            else{
                // target present in right sorted part
                if(nums[mid] <= target && nums[h] >= target)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return false;
    }