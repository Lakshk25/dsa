//  Brute Force

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int size = intervals.size();
        for(int i=0; i<size; i++){
            int start = arr[i][0];
            int end = arr[i][1];
            if(!ans.empty() && end <= ans.back()[1]) continue;
            for(int j=i+1; j<size; j++){
                if(arr[j][0] <= end)
                    end = max(end, arr[j][1]);
                else 
                    break;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};

// Optimised

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};