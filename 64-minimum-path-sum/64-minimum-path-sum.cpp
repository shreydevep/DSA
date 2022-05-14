class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        
        
        vector<int> prev(grid[0].size(),0);
        
        vector<int> curr(grid[0].size(),0);
        prev[0] = grid[0][0];
        
        for(int i=1;i<grid[0].size();++i){
            prev[i] = prev[i-1] + grid[0][i];
        }
        curr[0] = grid[0][0];
        for(int i=1;i<grid.size();++i){
            curr[0] += grid[i][0];
            for(int j=1;j<grid[i].size();++j){
                curr[j] = min(prev[j],curr[j-1]) + grid[i][j];
            }
            prev = curr;
        }
        return prev.back();
        
    }
};