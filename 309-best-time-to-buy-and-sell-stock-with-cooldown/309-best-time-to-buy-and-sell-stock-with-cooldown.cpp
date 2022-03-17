class Solution {
public:
    int dp[5001][2];
    int recurr(int day,bool buy,int last,vector<int> &prices){
        
        if(day >= prices.size()) 
        {
            return 0;
        }
        
        if(dp[day][buy] != -1){
            return dp[day][buy];
        }
        int ans1 = recurr(day+1,buy,last,prices);
        
        int ans2 = 0;
        
        
        if(!buy){
            ans2 = -prices[day] + recurr(day+1,1,prices[day],prices);
        }
        else{
           ans2 = prices[day] + recurr(day+2,0,0,prices);
        }
        return dp[day][buy] = max(ans1,ans2);
        
    }
    
    int maxProfit(vector<int>& prices) {
            for(int i=0;i<5001;++i){
                for(int j=0;j<2;++j){
                    dp[i][j] = -1;
                }
            }
            int ans = recurr(0,0,0,prices);
            return ans;
    }
};