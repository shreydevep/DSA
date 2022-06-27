class Solution {
public:
    struct DSU
{
  int connected;
  vector<int> par, sz;

  void init(int n)
  {
    par = sz = vector<int> (n + 1, 0);
    for (int i = 0; i <= n; i++)
      par[i] = i, sz[i] = 1;
    connected = n;
  }

  int getPar(int u)
  {
    while (u != par[u])
    {
      par[u] = par[par[u]];
      u = par[u];
    }
    return u;
  }

  int getSize(int u)
  {
    return sz[getPar(u)];
  }

  void unite(int u, int v)
  {
    int par1 = getPar(u), par2 = getPar(v);

    if (par1 == par2)
      return;

    connected--;

    if (sz[par1] > sz[par2])
      swap(par1, par2);

    sz[par2] += sz[par1];
    par[par1] = par[par2];
  }
};




struct Edge {
  int x;
  int y;
  int w;
};




static bool compare(const Edge &edge1, const  Edge &edge2) {
  return (edge1.w < edge2.w);
}

struct kruskals {
  vector<Edge> edges;
  vector<Edge> mstEgdes;
  DSU dsu;
  int cost = 0;
  void addEdge(int x, int y, int w) {
    Edge E;
    E.x = x;
    E.y = y;
    E.w = w;
    edges.push_back(E);
  }

  void sortEdges() {
    sort(edges.begin(), edges.end(), compare);
  }
  void init(int n) {
    // 0-based indexing
    dsu.init(n);
  }

  void runKruskals() {
    sortEdges();
    for (Edge e : edges) {
      if (dsu.getPar(e.x) != dsu.getPar(e.y)) {
        cost += e.w;
        //mstEgdes.push_back(e);
        dsu.unite(e.x, e.y);
      }
    }
  }
};
    int minCostConnectPoints(vector<vector<int>>& points) {
        kruskals graph;
        graph.init(points.size());
        for(int i=0;i<points.size();++i){
            for(int j=i+1;j<points.size();++j){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph.addEdge(i,j,dist);
            }
        }
        graph.runKruskals();
        return graph.cost;
    }
};