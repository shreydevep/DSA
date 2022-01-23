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
const ll N = 1e5 + 1;
vector <ll> adj[N];
vector <bool> vis(N, 0);
vector <ll> col(N, -1);
bool dfs_color(ll node, ll color) {
    vis[node] = 1;
    col[node] = color;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            if (dfs_color(child, !color) == 0) {
                return false;
            }
        }
        else {
            if (col[node] == col[child]) {
                return false;
            }
        }
    }
    return true;
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
        for (ll i = 0; i < n-1; ++i) {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        if(!dfs_color(0, 0)){
            cout << 0 <<"\n";
            return 0;
        }
        ll col0 = 0;
        ll col1 = 0;
        for (ll i = 0; i < n; ++i) {
            //cerr << i <<" "<< col[i] <<"\n";
            if (col[i]) {
                col1++;
            }
            else {
                col0++;
            }
        }
        ll total = col0 * col1;
        //cerr << col0 <<" "<< col1 <<"\n";
        cout << max(0ll, total - (n - 1)) << "\n";
    }
    return 0;
}