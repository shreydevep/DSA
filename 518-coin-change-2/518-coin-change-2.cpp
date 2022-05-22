class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //long long dp[coins.size()+1][amount+1];
       vector<int> prev(amount + 1,0);
       vector<int> curr(amount + 1,0);
       prev[0] = 1;
       
        
        for(int i=1;i<=coins.size();++i){
            curr[0] = 1;
            for(int j=1;j<=amount;++j){
                if(coins[i-1] <= j){
                    curr[j] = curr[j-coins[i-1]] + prev[j];
                }
                else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};