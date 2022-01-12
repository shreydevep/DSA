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


        vector <ll> freq(n + 1, 0ll);
        multiset <ll> s;
        vector <ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            while (a[i] > n) {
                a[i] /= 2;
            }
            s.insert(a[i]);
        }
        ll cnt = 0;
        while (cnt != n && s.size() > 0) {
            auto x = s.begin();
            ll val = (*x);
            s.erase(x);
            while (val > 0 && freq[val] == 1) {
                val /= 2;
            }
            if (val) {
                freq[val] = 1;
                cnt++;
            }


        }
        if (cnt == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}









