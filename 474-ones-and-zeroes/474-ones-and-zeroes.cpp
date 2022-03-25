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
    int dp[601][101][101] = {0};
    int recurr(int i,int m,int n,vector<string> &strs){
        if(i == strs.size()){
            return 0;
        }
        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }
        auto p = countOnesNzeros(strs[i]);
        if(p.first <= m && p.second <= n){
            return dp[i][m][n] = max(recurr(i+1,m-p.first,n-p.second,strs)+1,recurr(i+1,m,n,strs));
        }
        else{
            return dp[i][m][n] = recurr(i+1,m,n,strs);
        }
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0;i<strs.size()+1;++i){
            for(int j=0;j<m+1;++j){
                for(int k=0;k<n+1;++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        return recurr(0,m,n,strs);
    }
};