class Solution {
public:
    int recurr(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
        if(i >= text1.length() or j >= text2.length()) return 0;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + recurr(i+1,j+1,text1,text2,dp);
        }else{
            return dp[i][j] = max(recurr(i+1,j,text1,text2,dp),recurr(i,j+1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        
        return recurr(0,0,text1,text2,dp);
    }
};