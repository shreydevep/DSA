class Solution {
public:
    typedef pair<int,pair<int,int>> PPII;
    bool check(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return false;
        return true;
    }
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
    int bfs(vector<vector<int>> &grid){
        priority_queue<PPII,vector<PPII>,greater<PPII>> pq;
        pq.push({0,{0,0}});
        vector<vector<bool>> vis (grid.size(),vector<bool>(grid[0].size(),0));
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),1e5));
        vis[0][0] = 1;
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            auto [wt,p] = pq.top();
            auto [x,y] = p;
            pq.pop();
           
           for(int mv = 0;mv < 4; ++mv){
               if(check(x+dx[mv],y+dy[mv],grid,vis)){
                   int curr = max(0,grid[x+dx[mv]][y+dy[mv]] - dist[x][y]);
                   if (curr + dist[x][y]< dist[x+dx[mv]][y+dy[mv]]) {
                    dist[x+dx[mv]][y+dy[mv]] =  curr + dist[x][y];
                    //Correct
                    pq.push({dist[x+dx[mv]][y+dy[mv]], {x+dx[mv],y+dy[mv]}});
                    }
               }
           }
            
            
        }
        return dist[grid.size()-1][grid[0].size()-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};