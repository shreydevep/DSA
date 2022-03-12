class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        vector<int> prefectSqures;
        int len = sqrt(n) + 1;
        for(int i=0;i<=n;++i){
            dp[i] = i;
        }
         for(int i=1;i<=len;++i){
            prefectSqures.push_back(i*i);
            
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