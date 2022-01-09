#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << "\n";
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

vll seive;
void Seive()
{
    const ll maxn = 1e6 + 5;
    seive.resize(maxn);
    forn(i, maxn) seive[i] = i;
    forab(i, 2, maxn, 2)
        seive[i] = 2;
    seive[1] = -1;
    seive[0] = -1;
    for (ll i = 3; i <= maxn; i += 2)
        if (i == seive[i])
            for (ll j = i * i; j < maxn; j += i)
                if (seive[j] == j)
                    seive[j] = i;
}

ll extended_GCD(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_GCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modinv(ll a, ll mod = MOD)
{
    ll x, y;
    extended_GCD(a, mod, x, y);
    if (x < 0)
        x += mod;
    return x;
}

//Chinese Remainder Theoram
ll find_x_CRT(ll num[], ll rem[], ll n)
{
    ll pro = 1;
    forn(i, n)
        pro *= num[i];
    ll res = 0;
    forn(i, n)
    {
        ll pp = pro / num[i];
        res += (rem[i] * modinv(pp, num[i]) * pp);
    }
    res %= pro;
    return res;
}

ll power(ll a, ll b, ll m = MOD)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void precompute_NCR(vll &fact)
{
    const ll N = 1e6 + 5;
    fact[0] = 1;
    forab(i, 1, (N - 1), 1)
    {
        ll y = (i % MOD * fact[i - 1] % MOD) % MOD;
        fact[i] = y;
    }
}

ll NCR(vll &fact, ll N, ll R, ll mod = MOD)
{
    ll n = fact[N];
    ll r = fact[R];
    ll n_r = fact[N - R];
    ll y = (r % mod * n_r % mod) % mod;
    ll z = modinv(y, mod);
    ll ans = (n % mod * z % mod) % mod;
    return ans;
}
//Sparsh Table
void sparshTable(vector<vector<ll>> &sparsh, vector<ll> a, ll q = 1)
{
    ll n = a.size();
    const ll N = 2 * 1e5 + 5;
    const ll M = 50;

    for (ll i = 0; i < n; ++i)
    {
        sparsh[i][0] = a[i]; // from i next 1 elements minimum
    }

    for (ll jump = 1; jump <= (ll)(log2(n)); ++jump)
    {
        for (ll i = 0; i + (1 << jump) <= n; ++i)
        {
            sparsh[i][jump] = min(sparsh[i][jump - 1], sparsh[i + (1ll << (jump - 1))][(jump - 1)]);
            // from i next (jump - 1) elements minimum
        }
    }

    while (q--)
    {
        ll R, L;
        cin >> L >> R;
        L--;
        R--;
        ll j = log2(R - L + 1);
        // idempotent function i.e f(x,x) = x
        ll minimum = min(sparsh[L][j], sparsh[R - (1 << j) + 1][j]);
        //cout << minimum << "\n";
    }
}
//Segment Tree
const ll N = 2 * 1e5 + 1;
vector<ll> st(4 * N);
vector<ll> lazy(4 * N);
vector<ll> a;
// 1-based index segment tree
void build(ll node, ll start, ll end)
{
    if (start == end)
    {
        st[node] = a[start - 1];
    }
    else
    {
        //Recursion
        ll mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        //Internal Nodes
        st[node] = st[2 * node] + st[2 * node + 1];
    }
}

void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{

    if (lazy[node] != 0)
    {

        st[node] += (end - start + 1) * lazy[node]; // Update it

        if (start != end)
        {
            lazy[node * 2] += lazy[node];     // Mark child as lazy
            lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if ((start > end) || (start > r) || (end < l))
    { // Current segment is not within range [l, r]
        return;
    }

    if ((start >= l) && (end <= r))
    {
        // Segment is fully within range
        st[node] += (end - start + 1) * val;
        if (start != end)
        {
            // Not leaf node
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node * 2, start, mid, l, r, val);       // Updating left child
    updateRange(node * 2 + 1, mid + 1, end, l, r, val); // Updating right child
    st[node] = st[node * 2] + st[node * 2 + 1];         // Updating root with max value
}

ll queryRange(ll node, ll start, ll end, ll l, ll r)
{

    if ((start > end) || (start > r) || (end < l))
    {
        return 0; // Out of range
    }
    if (lazy[node] != 0)
    {
        // This node needs to be updated
        st[node] += (end - start + 1) * lazy[node]; // Update it
        if (start != end)
        {
            lazy[node * 2] += lazy[node];     // Mark child as lazy
            lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if ((start >= l) && (end <= r))
    { // Current segment is totally within range [l, r]
        return st[node];
    }
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node * 2, start, mid, l, r);       // Query left child
    ll p2 = queryRange(node * 2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

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

void init(ll n, vector<ll> &par, vector<ll> &sz)
{
    for (ll i = 0; i < n; ++i)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

ll find_set(ll node, vector<ll> &par, vector<ll> &sz)
{
    if (node == par[node])
    {
        return node;
    }
    return par[node] = find_set(par[node], par, sz);
}

void union_set(ll a, ll b, vector<ll> &par, vector<ll> &sz)
{
    a = find_set(a, par, sz);
    b = find_set(b, par, sz);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        par[b] = a;

        sz[a] += sz[b];
    }
}

int main()
{

    ISO();
    online_judge();
    ll tt;
    tt = 1;

    cin >> tt;
    ll T = tt;

    while (tt--)
    {
        string k;
        cin >> k;
        string k2 = k;
        ll i, j;
        i = 0;
        j = k.length() - 1;
        bool flag = 0;
        bool flag2 = 1;
        while (i <= j)
        {

            if (k2[i] >= k2[j])
            {
                k2[j] = k2[i];
            }
            else
            {
                flag2 = 0;
                break;
            }

            i++;
            j--;
        }
        if(flag2 && k2 != k){
            cout << k2 <<"\n";
            continue;
        }
        i = (k.length() - 1) / 2;
        j = (k.length()) / 2;

        while (i >= 0 && j < k.length())
        {
            if (flag)
            {
                k[j] = k[i];
            }
            else
            {
                if (k[i] == k[j])
                {
                    if (k[i] == '9' && !flag)
                    {
                        k[i] = '0';
                        k[j] = '0';
                    }
                    else
                    {
                        k[i] = (k[i] + 1);
                        k[j] = k[i];
                        flag = 1;
                    }
                }
                else
                {
                    for (char z = min(k[i], k[j]) + 1; z <= max(k[i], k[j]); ++z)
                    {
                        if (z >= k[i])
                        {
                            k[i] = z;
                            k[j] = k[i];
                            break;
                        }
                    }
                    flag = 1;
                }
            }
            // cerr << flag << " " << k[i] << " " << k[j] << " " << i << " " << j << "\n";
            i--;
            j++;
        }

        if (!flag)
        {
            k[k.length() - 1] = '1';
            cout << '1' << k << "\n";
        }
        else
            cout << k << "\n";
    }
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
    return 0;
}