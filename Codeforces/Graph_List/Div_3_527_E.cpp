//Ab bahut late ho gya :)
#include<bits/stdc++.h>
using namespace std;

#define tarzan ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long 

int rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
int cc[] = {1, 1, 0, -1, -1, -1, 0, 1};

const int mod = 1e9 + 7;
const int N = 3050;

vector<vector<int> > adj(N);
vector<int> vis(N), dis(N), par(N);
int mx = 0, node;

void dfs(int v) {
    vis[v] = 1;
    for(int u : adj[v]) {
        if(!vis[u]) {
            dis[u] = dis[v] + 1;
            if(dis[u] > mx) {
                mx = dis[u];
                node = u;
            }
            par[u] = v;
            dfs(u);
        }
    }
}

void empty() {
    fill(dis.begin(), dis.end(), 0);
    fill(vis.begin(), vis.end(), 0);
}

int find_center(int a, int b) {
    par[a] = -1;
    dfs(a);
    vector<int> vec;
    for(int u = b; u != -1; u = par[u]) {
        vec.push_back(u);
    }
    return vec[(int)(vec.size() / 2)];
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    tarzan;
    int test = 1;
    //cin >> test;
    while(test--) {
        int n, m;
        cin >> n >> m;
        while(m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<pair<int, int> > centers, edges;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                int r = i;
                mx = 0, node = i;
                dfs(i);
                r = node, mx = 0;
                empty();
                dfs(r);
                int diameter = mx;
                int center = find_center(r, node);
                centers.push_back({diameter, center});
            }
        }
        sort(centers.begin(), centers.end(), [&](pair<int, int> a, pair<int, int> b) {
            return (a.first > b.first);
        });
        int baap = centers[0].second;
        for(int i = 1; i < (int)centers.size(); i++) {
            edges.push_back({baap, centers[i].second});
            adj[baap].push_back(centers[i].second);
            adj[centers[i].second].push_back(baap);
        }
        empty();
        mx = 0, node = 1;
        dfs(1);
        empty();
        mx = 0;
        dfs(node);
        cout << mx << '\n';
        for(auto it : edges) {
            cout << it.first << ' ' << it.second << '\n';
        }
    }
    return 0;
}