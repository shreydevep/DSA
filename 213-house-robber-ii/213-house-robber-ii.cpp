class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        vector<vector<int>> dp(nums.size(),vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[0];
        dp[1][1] = nums[1];
        
        int n = nums.size();
        for(int i=2;i<n-1;++i){
            dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
            dp[i][1] = max({dp[i-1][0],dp[i-2][0],dp[i-2][1]}) + nums[i];
        }
        int ans = max(dp[n-2][0],dp[n-2][1]);
        dp[1][0] = 0;
        dp[1][1] = nums[1];
        dp[2][0] = nums[1];
        dp[2][1] = nums[2];
        for(int i=3;i<n;++i){
            dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
            dp[i][1] = max({dp[i-1][0],dp[i-2][0],dp[i-2][1]}) + nums[i];
        }
        ans = max({dp[n-1][0],dp[n-1][1],ans});
        return ans;
    }
};