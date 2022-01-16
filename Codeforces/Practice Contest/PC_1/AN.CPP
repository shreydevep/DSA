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
}


map<pair<ll, ll>, ll> mp;
vector <ll> adj[100001];
void init(ll n) {
    mp.clear();
    for(ll i=0;i<n;++i){
        adj[i].clear();
    }
}
void recurr(ll par, ll pm, vector <ll> &fin, vector<ll> &vis) {
    vis[par] = 1;
    for (auto child : adj[par]) {
        if (!vis[child]) {
            fin[mp[ {min(child, par), max(child, par)}]] = pm;
            if (pm == 2) {
                recurr(child, 3, fin, vis);
            }
            else {
                recurr(child, 2, fin, vis);
            }
        }
    }
}

int main() {

    ISO();
    online_judge();
    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        init(n);
        for (ll i = 0; i < n - 1; ++i) {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            mp[ {min(x, y), max(x, y)}] = i;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        ll cnt_2 = 0;
        ll cnt_3 = 0;
        ll root = 0;
        for (ll i = 0; i < n; ++i) {
            //cerr << i <<" "<<adj[i].size() <<"\n";
            if (adj[i].size() > 2) {
                cnt_3++;
            }


            if (adj[i].size() == 1) {
                root = i;
            }
        }
        //cerr << cnt_2 << " " << cnt_3 << "*\n";
        if (cnt_3) {
            cout << -1 << "\n";
        }
        else {
            // cerr << root <<"\n";
            vector <ll> fin(n + 1, 0);
            vector <ll> vis(n + 1, 0);
            recurr(root, 2, fin, vis);

            for (ll i = 0; i < n - 1; ++i) {
                cout << fin[i] << " ";
                
            }
            cout << "\n";
        }



    }
    return 0;
}