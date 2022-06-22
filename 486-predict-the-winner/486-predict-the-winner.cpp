class Solution {
public:
    vector<vector<int>> dp;
    int recurr(int i,int j,vector<int> &nums){
        
        if(i == j) return nums[i];
        
        if(dp[i][j] != -1) return dp[i][j];
        int takeFront = nums[i] - recurr(i+1,j,nums);
        int takeBack = nums[j] - recurr(i,j-1,nums);
        
        int ans = max(takeFront,takeBack);
        return  dp[i][j] = ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        for(auto x : nums) sum += x;
        
        int ans = recurr(0,nums.size()-1,nums);
        
        return (ans >= 0);
        
    }
};