class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        vector<int> prefectSqures;
        
        for(int i=1;i<=n;++i){
            prefectSqures.push_back(i*i);
            dp[i] = i;
        }
        for(int i=2;i<=n;++i){
            for(auto x : prefectSqures){
                if(x > i) break;
                
                dp[i] = min(dp[i],dp[i-x] + 1);
            }
        }
        return dp[n];
    }
};