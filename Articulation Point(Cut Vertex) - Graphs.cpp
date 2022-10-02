#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

void dfile() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void dfs(int node, int parent, vector<int> &vis, vector<int> &t_in, vector<int> &low, int &timer, vector<int> adj[], vector<int> &cutVertex) {
	vis[node] = 1;
	t_in[node] = low[node] = timer++;
	int child = 0;

	for (auto child : adj[node]) {
		if (child == parent) continue;

		if (!vis[child])
		{
			dfs(child, node, vis, t_in, low, timer, adj, cutVertex);
			low[node] = min(low[node], low[child]);
			if (low[child] >= t_in[node] and parent != -1)
			{
				cutVertex[node] = 1;
			}
			child++;
		}
		else {
			low[node] = min(low[node], t_in[child]);
		}
	}

	if (parent == -1 and child > 1)
	{
		cutVertex[node] = 1;
	}
}

void checkBridges(int v, vector<int> adj[]) {
	vector<int> t_in(v + 1, -1);
	vector<int> low(v + 1, -1);
	vector<int> vis(v + 1, 0);
	vector<int> cutVertex(v + 1, 0);

	int timer = 0;
	for (int i = 1; i <= v; ++i)
	{
		if (!vis[i])
		{
			dfs(i, -1, vis, t_in, low, timer, adj, cutVertex);
		}
	}

	for (int i = 0; i < cutVertex.size(); ++i)
	{
		if (cutVertex[i] == 1) cout << i << endl;
	}
}

int main()
{
	dfile();

	int n, m;
	cin >> n >> m;

	vector<int> adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	checkBridges(n, adj);


	return 0;
}


