class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = INT_MIN;
        if(currSum > maxSum){
            maxSum = currSum;
        }
        if(currSum < 0) currSum = 0;
        for(int i=1;i<nums.size();++i){
            maxSum = max(maxSum,nums[i]);
            currSum += nums[i];
            if(currSum > maxSum){
                maxSum = currSum;
            }
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};