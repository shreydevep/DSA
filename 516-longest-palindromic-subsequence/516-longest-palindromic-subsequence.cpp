class Solution {
public:
    vector<vector<int>> dp;
    int recurr(int i,int j,string &s){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]){
            return dp[i][j] = 2 + recurr(i+1,j-1,s);
        }
        else{
            return dp[i][j] = max(recurr(i+1,j,s),recurr(i,j-1,s));
        }
    }
    int longestPalindromeSubseq(string s) {
        dp.resize(s.length(),vector<int>(s.length(),-1));
        return recurr(0,s.length()-1,s);
    }
};