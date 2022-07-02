class Solution {
public:
    bool check(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return false;
        return true;
    }
    int bfs(vector<vector<int>> &grid){
        queue<pair<int,int>> q;
       
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),-1));
         if(grid[0][0] == 0){
            q.push({0,0});
             vis[0][0] = 1;
            dist[0][0] = 1;
        }
         
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i=-1;i<=1;++i){
                for(int j=-1;j<=1;++j){
                    if(check(x+i,y+j,grid,vis) && grid[x+i][y+j] == 0 && !vis[x+i][y+j]){
                        vis[x+i][y+j] = 1;
                        dist[x+i][y+j] = dist[x][y] + 1;
                        q.push({x+i,y+j});
                        
                    }
                }
            }
        }
        return (dist[grid.size()-1][grid[0].size()-1]);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};