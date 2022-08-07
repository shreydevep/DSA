class Solution {
public:
    int recurr(int i,int n,int buy,int trans,vector<vector<vector<int>>>&dp,vector <int> & prices){
        if(i >= n || trans >= 2){
            return 0;
        }
        if(dp[i][buy][trans] != -1){
            return dp[i][buy][trans];
        }
        if(buy){
            // buy or ignore
            return dp[i][buy][trans] = max(recurr(i+1,n,0,trans,dp,prices)-prices[i],recurr(i+1,n,1,trans,dp,prices));
        }
        else{
            return dp[i][buy][trans] = max(recurr(i+1,n,1,trans+1,dp,prices)+prices[i],recurr(i+1,n,0,trans,dp,prices));
        }
    }
    int iterative(vector<int> &price){
    
    vector<vector<int>> prev(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));
   for(int i=price.size()-1;i>=0;--i){
       for(int buy=0;buy<2;++buy){
           for(int trans=0;trans<2;trans++){
               //Buy ith stock or ignore
               if(buy == 1)
                curr[buy][trans] = max(prev[!buy][trans] - price[i],prev[buy][trans]);
               else
                curr[buy][trans] = max(prev[!buy][trans+1] + price[i],prev[buy][trans]);
           }    
       }
       prev = curr;
   }
   return prev[1][0];
    
}
    
    
    
    int maxProfit(vector<int>& prices) {
        
       return iterative(prices);
    }
};