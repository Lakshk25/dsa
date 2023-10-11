// Optimal 1  like kadane
    /*
    we know on multiplcation of two (-)ve numbers it becomes positive so here we take two products one is to take maximum value
    and prod2 is to get negative value we track neg value because if we get neg in array it changes to +ve and if it is max we store it in result
    */ 
    int maxProduct(vector<int>& nums) {
        int prod1 = nums[0], prod2 = nums[0], result = nums[0], size = nums.size();
        for(int i=1; i<size; i++){
            int temp = max({nums[i], prod1*nums[i], prod2*nums[i]});
            prod2 = min({nums[i], prod1*nums[i], prod2*nums[i]});
            prod1 = temp;
            result = max(result, prod1);
        }
        return result;
    }

    // Optimal Simplest
    /*
    here we track prefix sum and suffix sum {1,2,-3,0,2,3} in this we traverse array from both side prefix product left to right and suffix prod right to left
    and we update max value in maxProd in this way we get maxProd if prefix or suff prod is equal to 0 change it to 1
    */

        int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int preProd = 1, suffProd = 1;
        int size = nums.size();

        for(int i=0; i<size; i++){
            if(preProd == 0) {
                preProd = 1; 
            }
            if(suffProd == 0){
                suffProd = 1;
            }
                preProd *= nums[i];
                suffProd *= nums[size - i - 1];
                maxProd = max(maxProd, max(suffProd, preProd));
        }
        return maxProd;
    }