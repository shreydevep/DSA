class Solution {
public:
    int longestCommonSubsequence(string text1, string text2,vector<vector<int>> &dp) {
        
        for(int i=1;i<=text1.length();++i){
            for(int j=1;j<=text2.length();++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
    string shortestCommonSupersequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        longestCommonSubsequence(text1,text2,dp);
        
        int i=text1.length();
        int j=text2.length();
        string res;
        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                res += text1[i-1];
                --i;
                --j;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    res += text1[i-1];
                    --i;
                }
                else{
                    res += text2[j-1];
                    --j;
                }
            }
        }
    
       
         while(i > 0){
                res += text1[i-1];
                i--;
         }
         while(j > 0){
                res += text2[j-1];
                j--;
         }
        reverse(res.begin(),res.end());
        return res;
        
        
        
    }
};