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
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        return recurr(0,0,s,t,dp);
    }
};