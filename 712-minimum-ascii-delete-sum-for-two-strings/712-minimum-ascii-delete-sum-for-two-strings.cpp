class Solution {
public:
    int lcs(string s1,string s2){
        
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        
        for(int i=1;i<=s1.length();++i){
            for(int j=1;j<=s2.length();++j){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + (int)(s1[i-1]));
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
    int minimumDeleteSum(string s1, string s2) {
        int sum1  = 0;
        int sum2 = 0;
        for(auto &x : s1) {
            sum1 += (int)(x);
        }
        for(auto &x : s2){
            sum2 += (int)(x);
        }
        int lcs_sum = lcs(s1,s2);
        sum1 -= lcs_sum;
        sum2 -= lcs_sum;
        return (sum1+sum2);
    }
};