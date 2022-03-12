class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[coins.size() + 1][amount + 1];
        
        for(int i=0;i<=coins.size();++i){
            for(int j=0;j<=amount;++j){
                dp[i][j] = 10002;
            }
        }
        
        for(int i=1;i<=coins.size();++i){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=amount;++i){
            if(i % coins[0] == 0){
                dp[1][i] = i/coins[0];
            }
        }
        
         for(int i=1;i<=coins.size();++i){
            for(int j=1;j<=amount;++j){
           
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]] + 1);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[coins.size()][amount] == 10002) return -1;
        return dp[coins.size()][amount];
    }
};