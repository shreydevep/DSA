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
    //cin >> t;
    t = 1;
    while (t--) {

        ll n;
        cin >> n;
        ll l, k;
        cin >> l >> k;
        vector <ll> d(n);
        for (ll i = 0; i < n; ++i) {
            cin >> d[i];
        }
        vector <ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << a[0]*l << "\n";
            continue;
        }
        set <vector<pair<ll, ll>>> speed;
        vector<pair<ll, ll>> temp;
        temp.push_back({0, 0});
        temp.push_back({0, a[0]});
        temp.push_back({d[1], a[1]});
        speed.insert(temp);
        for (ll i = 1; i < n - 1; ++i) {
            vector<pair<ll, ll>> temp;
            temp.push_back({d[i - 1], a[i - 1]});
            temp.push_back({d[i], a[i]});
            temp.push_back({d[i + 1], a[i + 1]});
            speed.insert(temp);
        }

        temp.clear();

        temp.push_back({d[n - 2], a[n - 2]});
        temp.push_back({d[n - 1], a[n - 1]});
        temp.push_back({l, 0});
        speed.insert(temp);


        while (k) {
            ll total = 0;
            for (auto x : speed) {
                //cerr << x[1].second << "\n";
                total += (x[2].first - x[1].first) * x[1].second;
            }
         //   cerr << total << "\n";
            auto curr = speed.begin();
            for (auto itr = speed.begin(); itr != speed.end(); ++itr) {
                if (itr == speed.begin()) {
                    continue;
                }
                auto x = *itr;
                ll val1 = (x[2].first - x[1].first) * x[1].second;
                ll val2 = (x[2].first - x[1].first) * x[0].second;
                ll new_total = total - val1 + val2;
               // cerr << new_total << " " << total << " " << x[1].second << "\n";
                if (new_total < total) {
                    curr = itr;
                }
            }
            if (curr != speed.begin()) {

                auto prev = curr;
                prev--;
                auto nxt = curr;
                nxt++;
                auto prevval = *prev;
                auto currval = *curr;
                prevval[2] = currval[2];
                if (nxt != speed.end()) {
                    auto nextval = *nxt;
                    nextval[0] = currval[0];
                    speed.erase(nxt);
                    speed.insert(nextval);
                }
               // cerr << currval[1].second << "\n";
                speed.erase(curr);
                speed.erase(prev);
                speed.insert(prevval);
            }

            k--;
        }
        ll ans = 0;
        for (auto x : speed) {
            // cerr << x[1].first << "\n";
            ans += (x[2].first - x[1].first) * x[1].second;
        }
        cout << ans << "\n";

    }

    return 0;
}









