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
ll dp[505][505];
void memo() {
    for (ll i = 0; i < 505; ++i) {
        for (ll j = 0; j<505; ++j) {
            dp[i][j] = -1;
        }
    }
}
ll n;
ll recurr(ll i, ll k, vector<ll> &a, vector<ll> &d) {
    if (i == n) {
        return 0;
    }
    if (dp[i][k] != -1) return dp[i][k];
    ll temp = inf;
    for (ll j = i + 1; j < n + 1; ++j) {
        if (k - (j - i - 1) >= 0) {
            ll cst = (d[j] - d[i]) * a[i];
            temp = min(temp, cst + recurr(j, k - (j - i - 1),a,d));
        }
    }
    return dp[i][k] = temp;
}

int main() {

    ISO();
    online_judge();
    ll t;
    t = 1;
    // cin >> t;
    while (t--) {
        ll l, k;
        cin >> n >> l >> k;
        vector <ll> a(n);
        vector <ll> d(n);
        for (ll i = 0; i < n; ++i) {
            cin >> d[i];
        }
        d.push_back(l);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a.push_back(0);
        memo();
        cout << recurr(0,k,a,d) <<"\n";

    }

    return 0;
}









