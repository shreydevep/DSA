class Solution {
public:
    int integerBreak(int n) {
       int dp[59] = {1};
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;++i){
            dp[i] = i-1;
            for(int j=1;j<i;++j){
                dp[i] = max(max(dp[i-j],i-j)*max(j,dp[j]),dp[i]);
            }
        }
        
        return dp[n];
    }
};