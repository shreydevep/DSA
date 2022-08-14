class Solution {
public:
    int robber(int i,vector<int> &nums,vector<int> &dp){
        
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int pick = robber(i+2,nums,dp) + nums[i];
        int notpick = robber(i+1,nums,dp);
        
        return dp[i] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size()+1,-1);
        int ans1 = robber(1,nums,dp);
        fill(dp.begin(),dp.end(),-1);
        nums.pop_back();
        int ans2 = robber(0,nums,dp);
        return max(ans1,ans2);
    }
};