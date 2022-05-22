class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> prev(amount+1,10000002);
        vector<int> curr(amount+1,10000002);

        for(int j=0;j<=amount;++j){
            if(j % coins[0] == 0)
                prev[j] = (j/coins[0]);
        }
        curr = prev;
       
        for(int i=2;i<=coins.size();++i){
            curr[0] = 0;
            for(int j=0;j<=amount;++j){
                if(coins[i-1] <= j){
                    curr[j] = min(curr[j-coins[i-1]] + 1,prev[j]);
                }
                else{
                    curr[j] = prev[j];
                }
                
            }
            
            prev = curr;
        }
        if(prev[amount] == 10000002 && amount > 0) return -1;
        return prev[amount];
    }
};