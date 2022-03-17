class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
       int dp[9] = {0};
        dp[0] = 1;
        dp[1] = 10;
        
        for(int i=2;i<=8;++i){
           dp[i] = dp[i-1];
            int curr = 9;
            int ans = 9;
            for(int j=2;j<=i;++j){
                ans *= (curr);
                curr--;
            }
            
            dp[i] += ans;
        }
        return dp[n];
    }
    
};