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

int main() {

    ISO();
    online_judge();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector <ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll ans = -1;
        vector <vector<ll>> f(2e5, vector<ll>());

        for (ll i = 0; i < n; ++i) {
            f[a[i]].push_back(i);
        }
        for (auto x : f) {
            sort(x.begin(), x.end());
            if (x.size() > 0)
                for (ll i = 0; i < x.size() - 1; ++i) {
                    ll j = i + 1;
                    ll x1 = x[i];
                    ll x2 = x[j];
                    ll len = x1 + (n - x2 - 1) + 1;
                    ans = max(ans, len);
                }
        }
        cout << ans << "\n";

    }

    return 0;
}









