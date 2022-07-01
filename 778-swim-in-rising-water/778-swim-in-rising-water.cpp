class Solution {
public:
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
    bool check_bounds(int x,int y,vector<vector<int>> &grid){
        if((x < 0) || (y < 0) || (x >= grid.size()) || (y >= grid[0].size())){
            return false;
        }
        return true;
    }
    bool bfs(int limit_water,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        if(grid[0][0] > limit_water) q.pop();
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int mv=0;mv<4;++mv){
                if(check_bounds(x+dx[mv],y+dy[mv],grid) && !vis[x+dx[mv]][y+dy[mv]] && grid[x+dx[mv]][y+dy[mv]] <= limit_water){
                    vis[x+dx[mv]][y+dy[mv]] = 1;
                    q.push({x+dx[mv],y+dy[mv]});
                }
            }
        }
        return vis[grid.size()-1][grid[0].size()-1];
    }
    bool check(int water_limit,vector<vector<int>> &grid){
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        cout <<"\n";
        return bfs(water_limit,grid,vis);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int l = 0;
        int r = 5000;
        int ans = r;
        while(l < r){
            int mid = l + (r-l)/2;
            if(check(mid,grid)){
                ans = mid;
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};