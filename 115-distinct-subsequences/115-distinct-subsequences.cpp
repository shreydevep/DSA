class Solution {
public:
    int recurr(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(j >= t.length()) return 1;
        if(i >= s.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int nottake = recurr(i+1,j,s,t,dp);
        int take = 0;
        if(s[i] == t[j])
            take += recurr(i+1,j+1,s,t,dp);
            
        return dp[i][j] = take + nottake;
    }
    int iterative(string s,string t,vector<vector<double>> &dp){
        for(int i=0;i<=s.length();++i) dp[i][t.length()] = 1;
        
        for(int i=s.length()-1;i>=0;--i){
            for(int j=t.length()-1;j>=0;--j){
                if(s[i] == t[j]){
                    dp[i][j] = (dp[i+1][j+1] + dp[i+1][j]);
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(s.length()+1,vector<double>(t.length()+1,0));
        return iterative(s,t,dp);
    }
};