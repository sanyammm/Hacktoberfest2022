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

void bellmanFordAlgo(int v, int src, vector<ppi> edges) {

	vector<int> dist(v, INT_MAX);
	dist[src] = 0;

	for (int i = 0; i < v - 1; ++i)
	{
		for (auto it : edges) {
			int wt = it.first;
			int u = it.second.first;
			int v = it.second.second;

			if (dist[u] + wt < dist[v])
			{
				dist[v] = dist[u] + wt;
			}
		}
	}

	//To check if there is a -ive cycle or not!
	int flag = 0;
	for (auto it : edges) {
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;

		if (dist[u] + wt < dist[v])
		{
			cout << "Negative Cycle Exists!";
			flag = 1;
			break;
		}
	}

	if (!flag)
	{
		for (int i = 0; i < v; ++i)
		{
			cout << i << " -> " << dist[i] << endl;
		}
	}
}

int main()
{
	dfile();

	int n, m;
	cin >> n >> m;

	vector<ppi> edges;
	for (int i = 0; i < m; ++i)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({wt, {u, v}});
	}

	int src; cin >> src;

	bellmanFordAlgo(n, src, edges);


	return 0;
}


