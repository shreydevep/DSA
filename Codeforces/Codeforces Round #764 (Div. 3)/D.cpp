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
        ll n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector <ll> f(26, 0);  //abcdef
        ll cnt_pair = 0;
        ll cnt_single = 0;
        for (auto x : s) {
            f[(ll)(x - 'a')]++;
        }
        for (ll i = 0; i < 26; ++i) {
            cnt_pair += (f[i] / 2);
            cnt_single += (f[i] % 2);
        }

        ll ans = 0;
        ans += (2 * (cnt_pair / k));
        cnt_single += (2 * (cnt_pair % k));
        if (cnt_single >= k) {
            ans++;
        }


        cout << ans << "\n";

    }

    return 0;
}









