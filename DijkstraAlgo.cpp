class Dijkstra
{
    vector<vector<pair<ll, ll>>> grid;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll source, n, total_weight;

public:
    vector<ll> dist;
    vector<ll> parent;
    Dijkstra(vector<vector<pair<ll, ll>>> &grid, ll source)
    {
        this->grid = grid;
        this->source = source;
        this->total_weight = 0;
        n = grid.size();
        this->dist.resize(n, 1e18);
        this->parent.resize(n, -1);
    }
    void algo()
    {
        pq.push({0, source});
        dist[source] = 0;
        while (!pq.empty())
        {
            ll closest_dist = pq.top().first;
            ll node = pq.top().second;
            total_weight += dist[node];
            pq.pop();
            for (auto it : grid[node])
            {
                ll neighbour = it.first;
                ll edgeWeight = it.second;
                if (dist[node] + edgeWeight < dist[neighbour])
                {
                    dist[neighbour] = dist[node] + edgeWeight;
                    pq.push({dist[neighbour], neighbour});
                    parent[neighbour] = node;
                }
            }
        }
    }
    ll findTotalWeight()
    {
        return total_weight;
    }
    void printDijkstraTree()
    {
        fr(i, n)
        {
            cout << i << " " << parent[i] << endl;
        }
    }
};
