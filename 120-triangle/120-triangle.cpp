class Solution {
public:
    bool check(int i,int j,vector<vector<int>> &triangle){
        if(i > triangle.size() or j > i){
            return false;
        }
        return true;
    }
    int recurr(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i == triangle.size()) return 0;
        if(!check(i,j,triangle)) return triangle.size()+1;
        if(dp[i][j] != -1) return dp[i][j];
        int down = recurr(i+1,j,triangle,dp);
        int diagonal = recurr(i+1,j+1,triangle,dp);
        return dp[i][j] = min(down,diagonal) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        for(int i=0;i<triangle.size();++i){
            dp[i].resize(triangle[i].size(),-1);
        }
        return recurr(0,0,triangle,dp);
    }
};