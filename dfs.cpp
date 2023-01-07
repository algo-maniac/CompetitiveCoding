

void dfs(int node, vector<vector<int>>& adj, vector<int>& vst, vector<int>& ls, int &ct){
	vst[node]=1;
	ls.pb(node);
	for(auto it:adj[node]){
		if(!vst[it]){

			dfs(it, adj, vst, ls, ct);
		}
	}
}
vector<int> dfsOfGraph(int nodes, int V, vector<vector<int>>& adj, int &ct) {
	vector<int> vst(nodes+1, 0);
	vector<int> ls;
	dfs(V, adj, vst, ls, ct);
	return ls;
}
