class DSU
{
    vector<ll> parent, rank, components;

public:
    DSU(ll n)
    {
        parent.resize(n);
        rank.resize(n);
        components.resize(n, 1);
        fr(i, n)
        {
            parent[i] = i;
        }
    }
    void connect(ll x, ll y)
    {
        x = getLeader(x);
        y = getLeader(y);
        if (x == y)
        {
            return;
        }
        else if (rank[x] == rank[y])
        {
            rank[x]++;
            parent[y] = x;
            components[x] += components[y];
        }
        else if (rank[x] > rank[y])
        {
            parent[y] = x;
            components[x] += components[y];
        }
        else
        {
            parent[x] = y;
            components[y] += components[x];
        }
    }
    ll getLeader(ll x)
    {
        if (x == parent[x])
        {
            return x;
        }
        parent[x] = getLeader(parent[x]);
        components[x] = components[parent[x]];
        return parent[x];
    }
    ll num_components(ll x)
    {
        return components[x];
    }
    bool isSameComponent(ll x, ll y)
    {
        x = getLeader(x);
        y = getLeader(y);
        return x == y;
    }
};