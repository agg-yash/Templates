#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
const int inf = 1e18L;
const int mod = 1e9 + 7;

// O(V*E)
// can be used to detect negative weight cycle!
// Neg. weight SSSP
// we here store graph in vector of edges as it is more convenient here.

struct edge
{
	int a, b, cost;
};
int n, m;
vector<edge> e;
int dist[N];

void BellFord(int v)
{
	dist[v] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			if (dist[e[j].a] == inf) continue;
			dist[e[j].b] = min(dist[e[j].b], e[j].cost + dist[e[j].a]);
			dist[e[j].b] = max(dist[e[j].b], -inf);
		}
	}
	// n relaxations
	// If there are negative cycles, below part will mark all such vertices are -inf.

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			if (dist[e[j].a] == inf) continue;
			dist[e[j].b] = max(dist[e[j].b], -inf);
			if (dist[e[j].a] + e[j].cost < dist[e[j].b])
			{
				dist[e[j].b] = -inf;
			}
		}
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i <= n; i++)dist[i] = inf;

	return 0;
}