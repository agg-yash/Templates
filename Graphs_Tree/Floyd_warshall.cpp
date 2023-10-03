#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const long inf = 1e17L;
long d[N][N];
int n, m;


/*
	Dont forget to intialise all the d matrix to inf
	dont forget to intialisa all d[i][i]=0.
	then just set all d[i][j] which are connected to their orignal weights.
	do floyd.
	can't handle negative weight cycle.

	but can handle negative weights
	if there are no negative weights, consider djikstra for it.
	Floyd --> O(n^3)
	djikstra -->O(V^2 + EVLogV)
	But Djikstra cannot handle negative weights : )
*/

void floyd()
{
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (d[i][k] < inf && d[k][j] < inf)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n, m;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++ )d[i][j] = inf;
	for (int i = 0; i < n; i++)d[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		d[u][v] = min(d[u][v], w); // assuming directed here.
	}
	return 0;
}