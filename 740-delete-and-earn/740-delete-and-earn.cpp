class Solution {
public:
    map<int,int> mp;
    int recurr(int i,vector<int> &nums,vector<int> &dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
       
        
        int inclde = 0;
        auto itr = upper_bound(nums.begin()+i,nums.end(),nums[i]+1);
        int pos = itr - nums.begin();
        
        inclde = nums[i]*mp[nums[i]] + recurr(pos,nums,dp);
        
         int skip = 0;
        skip = recurr(i+1,nums,dp);
        
        
        return dp[i] = max(inclde,skip);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size()+1,-1);
        for(auto x : nums){
            mp[x]++;
        }
        
        return recurr(0,nums,dp);
    }
};