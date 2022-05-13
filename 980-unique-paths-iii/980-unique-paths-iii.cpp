class Solution {
public:
    vector<int> di= {-1,0,1,0};
    vector<int> dj = {0,1,0,-1};
    bool check(int i,int j,int x,int y,vector<vector<int>> &grid,set<pair<int,int>> &vis){
        if((i+x < 0) || (i + x >= grid.size()) || (j + y < 0) || j+y >= (grid[0].size())){
            return 0;
        }
        
        if(grid[i+x][j+y] == -1 || vis.find({i+x,j+y}) != vis.end()) return 0;
        
        return 1;
    }
    int recurr(int i,int j,int cnt,int &total,set<pair<int,int>> &vis,vector<vector<int>> &grid){
        if(grid[i][j] == 2 && cnt + 1 == total){
            return 1;
        }
        else if(grid[i][j] == 2 && cnt + 1 < total){
            return 0;
        }
        int ways = 0;
        for(int dx=0;dx<4;++dx){
            
                if(check(i,j,di[dx],dj[dx],grid,vis)){
                     vis.insert({i+di[dx],j+dj[dx]});
                     ways += recurr(i+di[dx],j+dj[dx],cnt+1,total,vis,grid);
                     vis.erase({i+di[dx],j+dj[dx]});
                
            }
        }
        return ways;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int total = 0;
        int startX = 0;
        int startY = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j] == 1){
                    startX = i;
                    startY = j;
                } 
                if(grid[i][j] == -1){
                    total++;
                }
            }
        }
        set<pair<int,int>> vis;
        
        total = (grid.size()*(grid[0].size())) - total;
        vis.insert({startX,startY});
        return recurr(startX,startY,0,total,vis,grid);
    }
};