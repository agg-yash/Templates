#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, 1, 0, -1};

// visualization: https://www.techiedelight.com/topological-sorting-dag/

vector<int> edges[N];
int ind[N];
vector<int> res;
void kahn(int n)
{
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (ind[i] == 0)q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front();
		res.push_back(cur);
		q.pop();
		for (int e : edges[cur])
		{
			ind[e]--;
			if (ind[e] == 0)q.push(e);
		}
	}
	cout << "Topo: ";
	for (int node : res)cout << node << " ";
}

int main()
{
	// if res contains less than n nodes. then not a valid topo sort.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		u--, v--;
		edges[u].push_back(v);
		ind[v]++;// in degree of v ++
	}
	kahn(n);
	return 0;
}