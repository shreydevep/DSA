class Solution {
public:
    int robLtoR(int l,int r,vector<int> &nums){
        vector<vector<int>> dp((nums.size()),vector<int>(2,0));
        dp[l][0] = 0;
        dp[l][1] = nums[l];
        for(int i=l+1;i<=r;++i){
            dp[i][1] = dp[i-1][0] + nums[i];
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        }
        return max(dp[r][0],dp[r][1]);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        return max(robLtoR(0,nums.size()-2,nums),robLtoR(1,nums.size()-1,nums));
    }
};