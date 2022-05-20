class Solution {
public:
    bool check(int i1,int j1,int i2,int j2,vector<vector<int>> &grid){
        int n = grid.size();
        if(i1 < 0 || i1 >= n) return 0;
        if(i2 < 0 || i2 >= n) return 0;
        if(j1 < 0 || j1 >= n) return 0;
        if(j2 < 0 || j2 >= n) return 0;
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1) return 0;
        return 1;
    }
    int maxPathSum(int i1,int j1,int i2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp) {
        int j2 = i1 + j1 - i2;
        
       if(!check(i1,j1,i2,j2,grid)) return -99999999;
        
       if(i1 == grid.size()-1 && j1 == grid.size()-1 && i2 == grid.size()-1 && j2 == grid.size()-1){
           int temp = grid[i1][j1] + grid[i1][j2];
            if(i1 == i2 && j1 == j2){
            temp /= 2;
            }
           return temp;
       }
        
        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];
        int x = maxPathSum(i1+1,j1,i2,grid,dp);
        
        int z = maxPathSum(i1+1,j1,i2+1,grid,dp);
        
        int y = maxPathSum(i1,j1+1,i2+1,grid,dp);
        
        int m = maxPathSum(i1,j1+1,i2,grid,dp);
        
        int temp = grid[i1][j1] + grid[i2][j2];
        
        if(i1 == i2 && j1 == j2){
            temp /= 2;
        }
       
        
       return dp[i1][j1][i2] = max(max(x,y),max(z,m)) + temp;
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid.size(),vector<int>(grid.size(),-1)));
            
            
            return max(maxPathSum(0,0,0,grid,dp),0);
    }
};