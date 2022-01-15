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
    t = 1;
    //cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector <ll> a(n);
        vector <ll> b(n);
        for (auto &x : a) {
            cin >> x;
        }
        for (auto &x : b) {
            cin >> x;
        }
        vector <ll> diff_p(n);
        vector <ll> diff_n(n);
        ll z = 0;
        for (ll i = 0; i < n; ++i) {
            diff_p[i] = a[i] - b[i];
            diff_n[i] = -1 * diff_p[i];
        }
        sort(diff_p.begin(), diff_p.end());
        sort(diff_n.begin(), diff_n.end());
        ll ans = 0;

        for (ll i = 0; i < n; ++i) {
            ll pos;
            if (diff_p[i] <= 0) {
                auto itr = lower_bound(diff_n.begin(), diff_n.end(), diff_p[i]);
                pos = itr - diff_n.begin();

            }
            else {
                auto itr = upper_bound(diff_p.begin() + i, diff_p.end(), -1 * diff_p[i]);

                pos = itr - diff_p.begin();
                pos = n - pos - 1;
                //cerr << diff_p[i] <<" "<< pos <<"\n";


            }
            // cerr << diff_p[i] << " " << pos << "\n";
            if (pos <= n) {
                ans += pos;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}