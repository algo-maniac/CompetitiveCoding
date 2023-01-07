

struct dsu {
    vector<ll> e;
    dsu(ll n) : e(n, -1) {}
    bool sameSet(ll a, ll b) { return find(a) == find(b); }
    ll size(ll x) { return -e[find(x)]; }
    ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};
 
