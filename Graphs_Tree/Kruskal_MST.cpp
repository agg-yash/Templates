#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
struct Edge {
	int u, v, w;
};

bool comp(Edge a , Edge b) // sort acc. to weights.
{
	if (a.w < b.w)return true;
	return false;
}

// USE DSU
long parent[N], siz[N];
long findParent(long i)
{
	if (parent[parent[i]] != parent[i])
		parent[i] = findParent(parent[i]);
	return parent[i];
}
void unionNodes(long a, long b)
{
	int parent_a = findParent(a), parent_b = findParent(b);
	if (parent_a == parent_b)
		return;
	if (siz[parent_a] >= siz[parent_b]) {
		swap(parent_a, parent_b);
	}
	siz[parent_b] += siz[parent_a];
	parent[parent_a] = parent_b;
	return;
}
void cleardsu(long n) {
	for (long i = 1; i <= n; i++) {
		parent[i] = i;
		siz[i] = 1;
	}
}

Edge a[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	cleardsu(n);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a, a + m, comp);
	long sum(0);
	for (int i = 0; i < m; ++i)
	{
		int p1 = findParent(a[i].u);
		int p2 = findParent(a[i].v);
		if (p1 != p2)
		{
			unionNodes(a[i].u, a[i].v);
			sum += a[i].w;
		}
	}
	cout << sum;
	return 0;
}