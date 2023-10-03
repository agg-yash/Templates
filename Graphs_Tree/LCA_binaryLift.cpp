#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

const int mxN = 33; // should be around log2N
vector<int> edges[N];
int lev[N], up[N][mxN + 2];

void dfs(int v, int lvl, int par)
{
	lev[v] = lvl;
	up[v][0] = par;
	for (int e : edges[v])
	{
		if (e != par)dfs(e, lvl + 1, v);
	}
}

void Binary_lifting(int n)
{
	dfs(1, 0, -1);
	for (int i = 1; i <= mxN; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (up[j][i - 1] != -1)
			{
				int par = up[j][i - 1];
				up[j][i] = up[par][i - 1];
			}
		}
	}
}

int get_lca(int a, int b)
{
	if (lev[b] < lev[a])swap(a, b);
	int d = lev[b] - lev[a];
	while (d > 0)
	{
		int i = log2(d);
		b = up[b][i];
		d -= (1LL << i);
	}
	if (a == b)return a;
	for (int i = mxN; i >= 0; i--)
	{
		if (up[a][i] != -1 && (up[a][i] != up[b][i]))
		{
			a = up[a][i], b = up[b][i];
		}
	}
	return up[a][0];
}

int getDist(int a, int b)
{
	int lca = get_lca(a, b);
	return lev[a] + lev[b] - 2 * lev[lca];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	// Important to intialise it to -1 ; )
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= mxN; j++)up[i][j] = -1;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v ; cin >> u >> v;
		edges[u].push_back(v), edges[v].push_back(u);
	}
	Binary_lifting(n);


	int q; cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << getDist(a , b) << '\n';
	}
	return 0;
}