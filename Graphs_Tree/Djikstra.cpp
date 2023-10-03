#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e15L;

// NOTE : DJIKSTRA can be used for finding Single source longest path . Just change signs of all edges and then do djikstra.
// Also note that, Djikstra can work if all edges are negative or all edges are positive : ).

vector<pair<int, int>> edges[N];
int dis[N];
int path[N]; // for restoring path if needed

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		dis[i] = inf;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}
	int v;
	cin >> v;
	dis[v] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	// {dis,node}
	q.push({0, v});
	while (!q.empty())
	{
		int cur = q.top().second;
		int wt = q.top().first;
		q.pop();
		if (wt != dis[cur])
			continue; // important optimization(because dis[cur] is the minimum distance ayee)
		for (auto p : edges[cur])
		{
			int e = p.first;	// Node e which is neighbour of cur
			int len = p.second; // Basically yhe current node se extra distance
			if (dis[cur] + len < dis[e])
			{
				dis[e] = dis[cur] + len;
				path[e] = cur;
				q.push({dis[e], e});
			}
		}
	}
}
