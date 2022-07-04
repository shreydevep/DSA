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
    int dfs(int id,unordered_set<int> &vis){
        int sum = 0;
        for(auto em : mp[id]->subordinates){
            if(vis.find(em) == vis.end()){
                vis.insert(em);
                sum += (dfs(em,vis));
            }
        }
        return sum + mp[id]->importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto x : employees){
            mp[x->id] = x;
        }
        unordered_set<int> vis;
        return dfs(id,vis);
        
    }
};