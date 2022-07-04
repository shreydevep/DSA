class Solution {
public:
    struct DSU{
      vector<int> par;
      vector<int> sz;
        
      void init(int n){
          par.resize(n,0);
          sz.resize(n,1);
          for(int i=0;i<n;++i){
              par[i] = i;
          }
      }
      int getPar(int x){
          while(x != par[x]){
              par[x] = par[par[x]];
              x = par[x];
          }
          return x;
      }
      void union_set(int x,int y){
          x = getPar(x);
          y = getPar(y);
          if(x == y) return;
          
          if(sz[x] > sz[y]) swap(x,y);
          
          sz[y] += sz[x];
          par[x] = y;
      }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu;
        dsu.init(isConnected.size());
        
        for(int i=0;i<isConnected.size();++i){
            for(int j=0;j<isConnected[0].size();++j){
                if(isConnected[i][j]) dsu.union_set(i,j);
            }
        }
        unordered_set<int> st;
        for(int i=0;i<isConnected.size();++i){
            st.insert(dsu.getPar(i));
        }
        return st.size();
    }
};