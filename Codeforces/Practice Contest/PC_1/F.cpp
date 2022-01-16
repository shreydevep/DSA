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
   // cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector <ll> a(n);
        for (auto &x : a) cin >> x;
        ll q;
        cin >> q;

        vector <ll> last_update(n + 1, 0);
        vector <ll> full_update(q + 1, -1);
        vector <ll> point(n + 1, -1);
        for (ll i = 0; i < q; ++i) {
            ll x;
            cin >> x;
            if (x == 1) {
                //Single person update
                ll p, val;
                cin >> p >> val;
                point[p - 1] = val;
                last_update[p - 1]  = i + 1;
            }
            else {
                ll val;
                cin >> val;
                full_update[i+1] = val;
            }
        }
        vector <ll> update(q+1,-1);
        ll mx = full_update[q];
        update[q] = full_update[q];
        for(ll i=q-1;i>=1;--i){
            mx = max(mx,full_update[i]);
            update[i] = mx;
        }

        for(ll p=0;p<n;++p){
            if(last_update[p] == 0){
                cout << max(a[p],mx) <<" ";
            }
            else{
                cout << max(point[p],update[last_update[p]]) <<" ";
            }
        }
        cout <<"\n";



    }
    return 0;
}