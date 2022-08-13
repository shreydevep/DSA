class Solution {
public:
    vector<vector<int>> dist;
    const int inf = 1e5;
    bool check(int x,int y,vector<vector<int>> &grid){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return 0;
        return 1;
    }
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
    void multisource_bfs(pair<int,int> node,vector<vector<int>> &grid){
        queue<pair<int,int>> q;
        q.push(node);
        while(!q.empty()){
            
            int sz = q.size();
            for(int i=0;i<sz;++i){
                auto [x,y] = q.front();
                q.pop();
                for(int mv=0;mv<4;++mv){
                    if(check(x+dx[mv],y+dy[mv],grid)&& grid[x+dx[mv]][y+dy[mv]] != 0 && dist[x][y] + 1 < dist[x+dx[mv]][y+dy[mv]]){
                        dist[x+dx[mv]][y+dy[mv]] = dist[x][y] + 1;
                        q.push({x+dx[mv],y+dy[mv]});
                    }
                }
            }
            
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        dist.resize(grid.size(),vector<int>(grid[0].size(),inf));
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j] == 2){
                    dist[i][j] = 0;
                    multisource_bfs({i,j},grid);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j] != 0)
                    ans = max(ans,dist[i][j]);
            }
        }
        if(ans == inf) return -1;
        return ans;
        
    }
};