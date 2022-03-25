class Solution {
public:
    pair<int,int> countOnesNzeros(string s){
        int ones = 0;
        int zeros = 0;
        for(auto x : s){
            if(x == '0') zeros++;
            else ones++;
        }
        return {zeros,ones};
    }
    
    int recurr(int i,int m,int n,vector<string> &strs,vector<vector<vector<int>>> &dp){
        if(i == strs.size()){
            return 0;
        }
        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }
        auto p = countOnesNzeros(strs[i]);
        if(p.first <= m && p.second <= n){
            return dp[i][m][n] = max(recurr(i+1,m-p.first,n-p.second,strs,dp)+1,recurr(i+1,m,n,strs,dp));
        }
        else{
            return dp[i][m][n] = recurr(i+1,m,n,strs,dp);
        }
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return recurr(0,m,n,strs,dp);
    }
};