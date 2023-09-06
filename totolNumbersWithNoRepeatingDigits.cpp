/* Author: SOUMYAJIT NASKAR */
#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// using namespace chrono;
// using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
// #define mod 10000000000007
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fr1(i, a, b) for (ll i = a; i <= b; i++)
#define frrev(i, a, b) for (ll i = a; i >= b; --i)
#define frds(i, ds) for (auto i = ds.begin(); i != ds.end(); ++i)
#define all(x) (x).begin(), (x).end()
#define inf (1 << 60)
#define lb(ds, x) lower_bound(ds.begin(), ds.end(), x)
#define ub(ds, x) upper_bound(ds.begin(), ds.end(), x)
// #define N 998244353
const static ll mod = 1000000007;
const static ll max_ll = 1e18;
// const static ll mod=998244353;

// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds;

const int N = 200002;
int primes[N + 1];

vector<ll> sieve(ll n)
{
    ll ct = 0;
    vector<bool> marked(n + 1, 1);
    vector<ll> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (marked[i] == 1)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                marked[j] = 0;
            }
        }
    }
    for (ll i = 2; i <= n; i++)
    {
        if (marked[i])
        {
            ans.pb(i);
        }
    }
    return ans;
}

int spf[N + 1];

void factor_by_sieve()
{
    fr(i, N + 1)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] != i)
            continue;
        for (int j = i * i; j <= N; j += i)
        {
            if (spf[j] == j)
            {
                spf[j] = i;
            }
        }
    }
}

set<ll> factors(ll x, vector<ll> &primes)
{
    set<ll> ans;
    for (auto p : primes)
    {
        if (p * p > x)
        {
            if (x > 1)
            {
                ans.insert(x);
                x = 1;
                break;
            }
        }
        else
        {
            while (x % p == 0)
            {
                ans.insert(p);
                x /= p;
            }
        }
    }
    return ans;
}

ll stringhash(string &s)
{
    ll h = 0;
    for (char c : s)
    {
        h = (h * 31 + (c - 'a' + 1)) % mod;
    }
    return h;
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1ll)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return res;
}

double giveSqrt(ll x)
{
    double low = 1, high = 3e9, ans = 1.0;
    ll t = 100;

    while (t--)
    {
        double mid = (low + high) / 2;

        if (mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

ll giveSqrtll(ll x)
{
    ll low = 1, high = 1000000000, ans = 1;
    ll t = 100;

    while (t--)
    {
        ll mid = (low + high) / 2;

        if (mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

bool cmp1(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first > b.first;
}

bool cmp4(pair<char, ll> a, pair<char, ll> b)
{
    return a.first < b.first;
}
bool cmp3(pair<ll, ll> a, pair<ll, ll> b)
{
    ll diff1 = a.second - a.first;
    ll diff2 = b.second - b.first;
    return diff1 <= diff2;
}
bool cmp2(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.first.first == b.first.first)
    {
        if (a.first.second == b.first.second)
        {
            return a.second < b.second;
        }
        return a.first.second < b.first.second;
    }
    return a.first.first > b.first.first;
}

void precal()
{
}

ll LCM(ll a, ll b)
{
    return (a * b) / (__gcd(a, b));
}

void dfs(vector<vector<ll>> &adj, ll i, vector<ll> &vis, ll &ct, ll &nb)
{
    vis[i] = 1;
    ct++;
    if (adj[i].size() == 1)
    {
        nb++;
    }
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(adj, it, vis, ct, nb);
        }
    }
}

ll get_query(ll a, ll b)
{
    cout << "? " << a << " " << b << endl;
    ll sum;
    cin >> sum;
    return sum;
}

ll fact[1000001];
void precompute_fact()
{
    fact[0] = 1;
    fr1(i, 1, 1000000)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll dp[10][2][(1 << 10)][2];

ll numDigits(string &s, ll ind, ll tight, ll mask, ll zero_check)
{
    if (s.size() == 1)
    {
        return s[ind] - '0' + 1;
    }
    if (ind == s.size())
    {
        // fr1(i,0,9){
        //     if((1<<i)&mask) cout<<1<<" ";
        //     else cout<<0<<" ";
        // }
        // cout<<endl;
        return 1;
    }
    if (dp[ind][tight][mask][zero_check] != -1)
        return dp[ind][tight][mask][zero_check];

    ll last = -1;
    if (tight == 1)
    {
        fr1(i, 0, (s[ind] - '0'))
        {
            if ((1 << i) & mask)
            {
                last = i;
            }
        }
    }
    else
    {
        fr1(i, 0, 9)
        {
            if ((1 << i) & mask)
            {
                last = i;
            }
        }
    }
    // cout<<last<<endl;
    if (last == -1)
        return 0;
    ll ans = 0;
    fr1(i, 0, last)
    {
        if (zero_check == 1 || i > 0)
        {
            if (tight == 1 && i == last)
            {
                if ((1 << i) & mask)
                {
                    ans += numDigits(s, ind + 1, 1, (1 << i) ^ mask, 1);
                }
            }
            else
            {
                if ((1 << i) & mask)
                {
                    ans += numDigits(s, ind + 1, 0, (1 << i) ^ mask, 1);
                }
            }
        }
        else
        {
            if (tight == 1 && i == last)
            {
                if ((1 << i) & mask)
                {
                    ans += numDigits(s, ind + 1, 1, mask, 0);
                }
            }
            else
            {
                if ((1 << i) & mask)
                {
                    ans += numDigits(s, ind + 1, 0, mask, 0);
                }
            }
        }
    }
    return dp[ind][tight][mask][zero_check] = ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    a--;
    string s = to_string(a);
    string t = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll cnt1 = numDigits(s, 0, 1, (1 << 10) - 1, 0);
    memset(dp, -1, sizeof(dp));
    ll cnt2 = numDigits(t, 0, 1, (1 << 10) - 1, 0);
    cout << cnt1 << endl;
    cout << cnt2 << endl;
    cout << cnt2 - cnt1 << endl;
}
int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);
    precal();
    ll t = 1;
    cin >> t;
    fr(i, t)
    {
        solve();
        fflush(stdout);
    }
    return 0;
}
