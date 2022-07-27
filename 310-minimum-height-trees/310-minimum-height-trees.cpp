class Solution {
public:
   
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj;
        vector<int> indegree(n,0);
        vector<int> ans;
        adj.resize(n);
        queue<int> q;
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        for(int i=0;i<n;++i){
            if(indegree[i] == 1){
                q.push(i);
                indegree[i]--;
            } 
        }
        int sz = q.size();
        while(!q.empty()){
            ans.clear();
            for(int i=0;i<sz;++i){
                auto node = q.front();
                ans.push_back(node);
                q.pop();
            
                for(auto &child : adj[node]){
                    if(indegree[child] == 0) continue;
                    indegree[child]--;
                    if(indegree[child] == 1){
                        q.push(child);
                        indegree[child]--;
                    }
                }
               
            }
             sz = q.size();
            
        }
        if(n == 1) ans.push_back(0);
        
        return ans;
        
    }
};