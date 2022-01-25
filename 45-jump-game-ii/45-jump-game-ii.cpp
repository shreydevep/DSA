class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size());
        fill(dp.begin(),dp.end(),100000);
        dp[0] = 0;
        for(int i=1;i<nums.size();++i){
            for(int j=max(i,1000);j>0;--j){
                if(i-j < 0){
                    continue;
                }
                if(i<= nums[i-j] + (i-j))
                    dp[i] = min(dp[i],dp[(i-j)] + 1);
            }
        }
       
        return dp[nums.size()-1];
    }
};