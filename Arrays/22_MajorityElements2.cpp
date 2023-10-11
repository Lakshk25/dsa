//  brute force
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int mini = (int)(size/3) + 1;
        vector<int>ans;

        for(int i=0; i<size; i++){
            int count = 0;
            if(ans.size() == 0 || ans[0] != nums[i]){
            for(int j=0; j<size; j++){
                if(nums[j] == nums[i]){
                    count++;
                }
            }
            if(count >= mini) ans.push_back(nums[i]);
            if(ans.size() == 2) break;
            }
        }
        return ans;
    }
};

// better 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int mini = (int)(size/3) + 1;
        vector<int>ans;
        map<int, int>mapping;

        for(int i=0; i<size; i++){
            mapping[nums[i]]++;

            if(mapping[nums[i]] == mini){
                ans.push_back(nums[i]);
            }
            if(ans.size() == 2) break;
        }
        return ans;
    }
};


// Optimal same like >n/2 elements 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int size = nums.size();
        int mini = (int)(size/3) + 1;
        vector<int>ans;
        for(int i=0; i<size; i++){
            if(count1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                count1++;
            }
            else if(count2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                count2++;
            }
            else if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
            else count1--, count2--;
        }
        count1 = 0, count2 = 0;
        for(int i=0; i<size; i++){
            if(nums[i] == ele1){
                count1++;
            }
            else if(nums[i] == ele2){
                count2++;
            }
        }
        if(count1 >= mini){
            ans.push_back(ele1);
        }
        if(count2 >= mini){
            ans.push_back(ele2);
        }
        return ans;
    }
};