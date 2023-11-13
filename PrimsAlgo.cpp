class PrimsAlgorithm
{
    ll n;
    vector<vector<pair<ll, ll>>> grid;

public:
    vector<ll> parent, vis, dist;
    ll total_weight;
    PrimsAlgorithm(vector<vector<pair<ll, ll>>> &grid)
    {
        n = grid.size();
        this->grid = grid;
        this->parent.resize(n, -1);
        this->dist.resize(n, 1e18);
        this->vis.resize(n);
        this->total_weight = 0;
    }
    void algo()
    {
        set<pair<ll, ll>> st;
        dist[0] = 0;
        st.insert({0, 0});
        fr(i, n)
        {
            pair<ll, ll> top = *st.begin();
            st.erase(top);
            ll node = top.second;
            vis[node] = 1;
            for (auto it : grid[node])
            {
                ll edgeWeight = it.second;
                ll neighbour = it.first;
                if (!vis[neighbour] && dist[neighbour] > edgeWeight)
                {
                    st.erase({dist[neighbour], neighbour});
                    dist[neighbour] = edgeWeight;
                    st.insert({dist[neighbour], neighbour});
                    parent[neighbour] = node;
                }
            }
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
