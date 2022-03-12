class Solution {
public:
    vector<int> dp;
    int recurr(int house_pos,vector<int> &nums){
        if(house_pos >= nums.size()) return 0;
        if(dp[house_pos] != -1) return dp[house_pos];
        return dp[house_pos] = max(nums[house_pos] + recurr(house_pos+2,nums),recurr(house_pos+1,nums));
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size());
        fill(dp.begin(),dp.end(),-1);
        return recurr(0,nums);
    }
};