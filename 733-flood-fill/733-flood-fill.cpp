class Solution {
public:
    bool check(int i,int j,int &req,vector<vector<int>> &image,vector<vector<bool>> &vis){
        if((i < 0) || j < 0 || i >= vis.size() || j >= vis[0].size() || (vis[i][j])) return 0;
        
        if(image[i][j] != req) return 0;
        return 1;
    }
    vector<int> dx = {0,-1,1,0};
    vector<int> dy = {-1,0,0,1};
    void dfs(int i,int j,int &color,int &req,vector<vector<int>>& image,vector<vector<bool>> &vis){
        vis[i][j] = 1;
        image[i][j] = color;
        for(int mv=0;mv<4;++mv){
            if(check(i+dx[mv],j+dy[mv],req,image,vis)){
                dfs(i+dx[mv],j+dy[mv],color,req,image,vis);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> vis(image.size(),vector<bool>(image[0].size(),0));
        int req = image[sr][sc];
        dfs(sr,sc,color,req,image,vis);
        return image;
    }
};