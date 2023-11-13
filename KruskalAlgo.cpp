class KruskalAlgorithm
{
    ll n;
    vector<vector<pair<ll, ll>>> grid;
    vector<pair<ll, pair<ll, ll>>> edges;

public:
    vector<ll> parent;
    ll total_weight;
    KruskalAlgorithm(vector<vector<pair<ll, ll>>> &grid)
    {
        n = grid.size();
        this->grid = grid;
        this->parent.resize(n, -1);
        this->total_weight = 0;
        vector<ll> vis(n);
        fr(i, n)
        {
            for (auto it : grid[i])
            {
                edges.pb({it.second, {i, it.first}});
            }
        }
        sort(all(edges));
    }
    void algo()
    {
        DSU *dsu = new DSU(n);
        for (auto it : edges)
        {
            ll x = it.second.first;
            ll y = it.second.second;
            ll weight = it.first;
            if (dsu->isSameComponent(x, y))
                continue;
            dsu->connect(x, y);
            parent[x] = y;
            total_weight += weight;
        }
    }
    void printMST()
    {
        fr(i, n)
        {
            cout << i << " " << parent[i] << endl;
        }
    }
};