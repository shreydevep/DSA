class Solution {
public:
    //Cycle Detection in a directed Graph
    
    //Check for Backedge
    vector<bool> vis;
    void dfs(int node,vector<vector<int>> &rooms){
        for(auto &child : rooms[node]){
            if(!vis[child]){
                vis[child] = 1;
                dfs(child,rooms);
            }
          
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size(),0);
        bool ans = true;
        vis[0] = 1;
        dfs(0,rooms);
        for(int i=0;i<rooms.size();++i) ans = ans & vis[i];
        
        return ans;
    }
};