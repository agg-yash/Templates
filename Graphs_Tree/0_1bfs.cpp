#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

vector<pair<int, int>> edges[N];
vector<int> lev(N, INT_MAX);

void bfs(int v)
{
	deque<int> q;
	lev[v] = 0;
	q.push_front(v);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop_front();
		for (auto e : edges[cur])
		{
			int u = e.first;  // child
			int w = e.second; // weight
			int new_dis = lev[cur] + w;
			if (new_dis < lev[u])
			{
				lev[u] = new_dis;
				if (w == 1)
					q.push_back(u);
				else
					q.push_front(u);
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
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[u].push_back({v, 0});
		edges[v].push_back({u, 1});
	}
	bfs(0);

	return 0;
}