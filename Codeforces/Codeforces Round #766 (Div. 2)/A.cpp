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
ll recurr(ll n) {
    ll temp = 0;
    bool flag = 0;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            flag = 1;
            temp = max(temp, max(n / i, i));
        }
    }
    if (flag) {
        return temp + recurr(temp);
    }
    else
        return 1;
}
int main() {

    ISO();
    online_judge();
    ll t;
    t = 1;
     cin >> t;
    while (t--) {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;
        r--;
        c--;
        int black = 0;
        vector<vector<char>> grid(n, vector<char>(m));
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'B') black++;
            }
        }
        if (black == 0) {
            cout << -1 << "\n";
            continue;
        }

        if (grid[r][c] == 'B') {
            cout << 0 << "\n";
            continue;
        }
        bool rw = 0;
        for (ll i = 0; i < n; ++i) {
            if (grid[i][c] == 'B') rw = 1;
        }
        for (ll j = 0; j < m; ++j) {
            if (grid[r][j] == 'B') rw = 1;
        }
        if (rw) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
        }




    }
    return 0;
}