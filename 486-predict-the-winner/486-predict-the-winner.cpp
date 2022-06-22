class Solution {
public:
    vector<vector<int>> dp;
    int recurr(int i,int j,bool chance,vector<int> &nums){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int takeFront = recurr(i+1,j,!chance,nums);
        int takeBack = recurr(i,j-1,!chance,nums);
        
        int ans = max(takeFront + nums[i],takeBack + nums[j]);
        return  dp[i][j] = (chance == 0) ? ans : min(takeFront,takeBack);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums) sum += x;
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        
        int ans = recurr(0,nums.size()-1,0,nums);
        
        if((sum-ans) > ans) return 0;
        return 1;
    }
};