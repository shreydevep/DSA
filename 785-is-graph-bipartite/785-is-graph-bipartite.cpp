class Solution {
public:
    bool graph_color(int node,bool col,vector<bool> &vis,vector<bool> &color,vector<vector<int>> &graph){
        color[node] = col;
        vis[node] = 1;
        for(auto &child : graph[node]){
            if(!vis[child]){
                if(!graph_color(child,!col,vis,color,graph)) return false;
            }
            else{
                if(color[child] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> color(graph.size()+1,0);
        vector<bool> vis(graph.size()+1,0);
        bool ans = true;
        for(int i=0;i<graph.size();++i){
            if(!vis[i]){
                ans = (ans & graph_color(i,0,vis,color,graph));
            }
        }
        return ans;
    }
};