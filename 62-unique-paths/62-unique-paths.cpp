
class Solution {
public:
    int recurr(int i,int j,int &m,int &n,vector<vector<int>> &dp){
        if(i >= m or j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right =  recurr(i,j+1,m,n,dp);
        int down =   recurr(i+1,j,m,n,dp);
        return dp[i][j] = (right + down);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recurr(0,0,m,n,dp);
    }
};