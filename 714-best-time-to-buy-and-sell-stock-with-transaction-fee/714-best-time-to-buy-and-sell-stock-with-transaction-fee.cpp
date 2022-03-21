class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        int dp[50001][3] = {0};
        //0 Nothing
        //1 Buy
        //2 Sell
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        dp[1][2] = INT_MIN;
        int valUpto = -prices[0];
        for(int i=2;i<=prices.size();++i){
            
            dp[i][0] = max({dp[i-1][0],dp[i-1][2]});
            dp[i][1] = -prices[i-1] + max({dp[i-1][0],dp[i-1][2]});
            dp[i][2] = prices[i-1] - fee + valUpto;
            
            valUpto = max(valUpto,dp[i][1]);
            
            
        }
        
        return max(dp[prices.size()][0],dp[prices.size()][2]);
        
    }
};