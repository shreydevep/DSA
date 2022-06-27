class Solution {
public:
    struct Edge{
        int a;
        int b;
        int cost;
    };
    
    struct bellman_ford{
      vector<Edge> edges;
      vector<int> dist;
      int INF = 1e7;
      void init(vector<vector<int>> &times,int n){
          for(auto &z : times){
              Edge e;
              e.a = z[0]-1;
              e.b = z[1]-1;
              e.cost = z[2];
              edges.push_back(e);
          }
          dist.resize(n,INF);
      }
      
      int minTimeNetwork(int n,int k){
          dist[k-1] = 0;
          for(int phase=0;phase< n;++phase){
             bool any = false;
            for (int j = 0; j < edges.size(); ++j){
                if (dist[edges[j].a] < INF)
                    if (dist[edges[j].b] > dist[edges[j].a] + edges[j].cost)
                    {
                        dist[edges[j].b] = dist[edges[j].a] + edges[j].cost; 
                        any = true;
                    }
            }
            if (!any)  break;
          }
          
          int ans = 0;
          for(int i=0;i<n;++i){
              cout << dist[i] <<" ";
              if(dist[i] == INF) return -1;
              ans = max(ans,dist[i]);
          }
          return ans;
      }
        
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        bellman_ford graph;
        graph.init(times,n);
        return graph.minTimeNetwork(n,k);
    }
};