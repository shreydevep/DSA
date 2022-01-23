#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define inf 1e18
#define MAXN 10000001
#define PI 3.141592653589793238462

#define ll long long
#define pb push_back
#define mkp make_pair
#define pll pair<ll, ll>
#define vll vector<int>
#define mll map<ll, ll>
#define pqg priority_queue<ll>
#define pqs priority_queue<ll, vll, greater<ll>>
#define ull unsigned long long
#define lld long double
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

#define ps(x, y) fixed << setprecision(y) << x

#define forn(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define for1(i, n) for (ll(i) = 1; (i) <= (n); ++(i))
#define forr(i, n) for (ll(i) = (n)-1; (i) >= 0; --(i))
#define forab(i, a, b, c) for (ll(i) = a; (i) <= (b); (i) += (c))


void online_judge()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

void ISO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // For Factorial uncomment Fact array!!!
    // Check Sieve upper bound
    //GPG Key Setup Complete
}
const ll N = 2e5 + 1;
vector <ll> adj[N];
vector <bool> vis(N, 0);
vector <ll> backedge(N, 0);
void dfs(ll node, ll par) {
    vis[node] = 1;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, node);
            backedge[node]++;
            backedge[child]++;
        }
        else {
            if (child == par)
                continue;
            else {
                backedge[child]++;
            }
        }
    }
}
vector <pair<ll, ll>> res;
void bfs(ll node) {
    priority_queue <pair<ll, ll>> q;
    q.push({backedge[node], node});
    while (!q.empty()) {
        auto curr = q.top();
        q.pop();
        vis[curr.second] = 0;
        for (auto child : adj[curr.second]) {
            if (vis[child]) {
                res.push_back({child, curr.second});
                q.push({backedge[child], child});
                vis[child] = 0;
            }
        }
        //vis[curr.second] = 0;
    }

}
int main() {

    ISO();
    online_judge();
    ll t;
    t = 1;
    //cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll m;
        cin >> m;
        for (ll i = 0; i < m; ++i) {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0, -1);
        ll curr = 0;
        for (ll i = 0; i < n; ++i) {
            if (backedge[curr] < backedge[i])
                curr = i;
           // cerr << i << " " << backedge[i] << "\n";
        }
        bfs(curr);
        for (auto x : res) {
            cout << x.first + 1 << " " << x.second + 1 << "\n";
        }

    }
    return 0;
}