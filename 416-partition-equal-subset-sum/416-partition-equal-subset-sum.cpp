class Solution {
public:
    bool subsetSum(vector<int> &nums,int totalSum,vector<vector<bool>> &dp){
        if(totalSum & 1) return false;
        
        
        for(int i=0;i<=totalSum;++i){
            dp[i][0] = false;
        }
        for(int j=0;j<=nums.size();++j){
            dp[0][j] = true;
        }
        
       for(int i=1;i<=totalSum;++i){
           for(int j=1;j<=nums.size();++j){
               
               if(nums[j-1] <= i){
                   dp[i][j] = (dp[i-nums[j-1]][j-1] or dp[i][j-1]);
               }
               else{
                   dp[i][j] = dp[i][j-1];
               }
           }
       }
        
        
      for(int j=0;j<=nums.size();++j){
          if(dp[totalSum/2][j]) return 1;
      }
      return 0;
        
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0;i<nums.size();++i){
            totalSum += nums[i];
        }
        vector<vector<bool>> dp(totalSum+1,vector<bool>(nums.size()+1,0));
        return subsetSum(nums,totalSum,dp);
    }
};