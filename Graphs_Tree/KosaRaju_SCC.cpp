#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 1010;
const int mod = 1e9 + 7;
vector<int> edges[N];
vector<int> tran[N];
vector<int> order, SCC;
bool vis[N];
int n, m;
void dfs(int v)
{
	vis[v] = true;
	for (int e : edges[v])
	{
		if (!vis[e])dfs(e);
	}
	order.push_back(v);
}

void dfs1(int v)
{
	vis[v] = true;
	for (int e : tran[v])
	{
		if (!vis[e])dfs1(e);
	}
	SCC.push_back(v);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)edges[i].clear(), tran[i].clear(), vis[i] = false;
		order.clear();
		for (int i = 1; i <= m; i++)
		{
			int u, v; cin >> u >> v;
			edges[u].push_back(v);
			tran[v].push_back(u); // transposed graph --> reverse directed edges
		}
		for (int i = 1; i <= n; i++)if (!vis[i])dfs(i);
		for (int i = 1; i <= n; i++)vis[i] = false;
		reverse(order.begin(), order.end());
		for (int i : order)
		{
			if (!vis[i])
			{
				SCC.clear();
				dfs1(i);
				cout << "Dfs1 called from " << i << " and printing SCC\n";
				for (int node : SCC)cout << node << " ";
				cout << '\n';
			}
		}
	}

	return 0;
}