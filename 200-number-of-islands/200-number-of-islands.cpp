class Solution {
public:
    // left, up, down ,right
    vector <int> dy = {-1,0,0,1};
    vector <int> dx = {0,1,-1,0};
    void dfs(int i,int j,vector<vector<char>> &grid,vector <vector<bool>> &vis){
        vis[i][j] = 1;
        //cout << i <<" " << j <<"->\n";
        for(int mv=0;mv<4;++mv){
            
            if((i+dx[mv]) < 0 || (i + dx[mv]) >= grid.size() || (j + dy[mv]) < 0 || (j + dy[mv]) >= grid[i].size()){
                continue;
            }
            
            if(grid[i+dx[mv]][j+dy[mv]] == '1' && vis[i+dx[mv]][j+dy[mv]] == 0){
                //cout << i + dx[mv] <<" " << j + dy[mv] <<"\n";
                dfs(i+dx[mv],j+dy[mv],grid,vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        int ans = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid,vis);
                    
                }
            }
        }
        return ans;
    }
};