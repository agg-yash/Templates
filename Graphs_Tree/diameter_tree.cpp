#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
vector<int> edges[N];
int depth[N];
void dfs(int v, int par = -1)
{
	for (int e : edges[v])
	{
		if (e == par)continue;
		depth[e] = depth[v] + 1;
		dfs(e, v);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1); // from any node
	int mx_depth_node;
	int mx_depth = -1;
	for (int i = 1; i <= n; i++)
	{
		if (mx_depth < depth[i])
		{
			mx_depth = depth[i];
			mx_depth_node = i;
		}
		depth[i] = 0;
	}
	dfs(mx_depth_node);
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, depth[i]);
	}
	cout << ans;
	return 0;
}