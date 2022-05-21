class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,10000002));
        
        for(int i=0;i<=coins.size();++i){
            dp[i][0] = 0;
        }
        for(int j=0;j<=amount;++j){
            if(j % coins[0] == 0)
                dp[1][j] = (j/coins[0]);
            else dp[1][j] = 10000002;
        }
        
        for(int i=1;i<=amount;++i){
            for(int j=2;j<=coins.size();++j){
                if(coins[j-1] <= i)
                    dp[j][i] = min(dp[j][i-coins[j-1]] + 1,dp[j-1][i]);
                else 
                    dp[j][i] = dp[j-1][i];
            }
        }
        
        if(amount != 0 && dp[coins.size()][amount] == 10000002) return -1;
        return dp[coins.size()][amount];
    }
};