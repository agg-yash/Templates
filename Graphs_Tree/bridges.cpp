#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, 1, 0, -1};
vector<int> edges[N];
bool vis[N];
int timer;
int in[N], low[N];
void dfs(int v, int par = -1)
{
	// when i enter node v
	vis[v] = true;
	in[v] = low[v] = timer++;
	for (int e : edges[v])
	{
		// when i am checking before entering node e
		if (e == par)continue;
		if (vis[e])
		{
			// this is a back edge
			low[v] = min(low[v], in[e]);
		}
		else
		{
			//forward edge--> maybe a bridge
			dfs(e, v);
			// while exiting from node e
			if (low[e] > in[v])
			{
				cout << v << " - " << e << " is a bridge\n";
			}

			low[v] = min(low[v], low[e]);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1);


	return 0;
}