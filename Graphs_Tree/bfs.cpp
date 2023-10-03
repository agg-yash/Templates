#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, 1, 0, -1};
vector<int> edges[N];
bool vis[N];

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	vis[v] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int e : edges[cur])
		{
			if (!vis[e])
			{
				vis[e] = true;
				q.push(e);
			}
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
	bfs(1);


	return 0;
}