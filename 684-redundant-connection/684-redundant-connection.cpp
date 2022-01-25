class Solution {
public:
    vector <int> par;
    vector <int> sz;
    void init(int n){
        for(int i=0;i<=n;++i){
            par.push_back(i);
            sz.push_back(1);
        }
    }
    
    int find_set(int x){
        if(x == par[x]) return par[x];
            return par[x] = find_set(par[x]);
    }
    void union_set(int a,int b){
        a = find_set(a);
        b = find_set(b);
        
        if(a != b){
            if(sz[a] < sz[b]){
                swap(a,b);
            }
            par[b] = a;
            sz[a] += sz[b];
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       init(edges.size());
        for(auto edge: edges){
            if(find_set(edge[0]) == find_set(edge[1])){
                return edge;
            }
            union_set(edge[0],edge[1]);
        }
        return edges.back();
    }
};