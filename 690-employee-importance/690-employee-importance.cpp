/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,Employee*> mp;
    int dfs(int id,vector<bool> &vis){
        int sum = 0;
        for(auto em : mp[id]->subordinates){
            if(!vis[em]){
                vis[em] = 1;
                sum += (dfs(em,vis));
            }
        }
        return sum + mp[id]->importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto x : employees){
            mp[x->id] = x;
        }
        vector<bool> vis(2002,0);
        return dfs(id,vis);
        
    }
};