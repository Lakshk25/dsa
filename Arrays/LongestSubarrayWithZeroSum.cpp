#include<vector>
#include<map>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	map<int, int>preSum;
	int sum = 0;
	int maxLen = 0;

	for(int i=0; i<arr.size(); i++){
		sum += arr[i];

		if(sum == 0){
			maxLen = max(maxLen, i+1);
		}
		int rem = sum;
		if(preSum.find(rem) != preSum.end()){
			int len = i - preSum[rem];
			maxLen = max(maxLen, len);
		}
		else{
			preSum[sum] = i;
		}
	}
	return maxLen;
}