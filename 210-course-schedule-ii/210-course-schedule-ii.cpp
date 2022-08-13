class Solution {
public:
    vector<int> topologicalSort(queue<int> &q,vector<vector<int>> &adj,vector<int> &indegree){
       
        vector<int> res;
       
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            res.push_back(node);
            
            
            for(auto &child : adj[node]){
                indegree[child]--;
                
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
            
        }
        return res;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj;
        adj.resize(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &x : prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();++i){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        auto res = topologicalSort(q,adj,indegree);
        if(res.size() < numCourses) return vector<int>();
        return res;
    }
};