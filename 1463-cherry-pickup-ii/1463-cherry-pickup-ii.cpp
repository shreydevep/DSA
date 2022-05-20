class Solution {
public:
    bool check(int i,int j1,int j2,vector<vector<int>> &grid){
        if(i < 0 || i >= grid.size()) return 0;
        if(j1 < 0 || j1 >= grid[0].size()) return 0;
        if(j2 < 0 || j2 >= grid[0].size()) return 0;
        if(grid[i][j1] == -1 || grid[i][j2] == -1) return 0;
        return 1;
    }
    int pathSum(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(!check(i,j1,j2,grid)) return -99999999;
        
        if(i == grid.size()-1){
            int temp = grid[i][j1] + grid[i][j2];
            if(j1 == j2) temp /= 2;
            
            return temp;
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int currAns = -99999999;
        int temp = 0;
        
        temp = grid[i][j1] + grid[i][j2];
        if(j1 == j2) temp /= 2;
        
        for(int a=-1;a<2;++a){
            for(int b=-1;b<2;++b){
                currAns = max(currAns,pathSum(i+1,j1+a,j2+b,grid,dp));
            }
        }
        return dp[i][j1][j2] = currAns + temp;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>> (grid[0].size(),vector<int>(grid[0].size(),-1)));
        return pathSum(0,0,grid[0].size()-1,grid,dp);
    }
};