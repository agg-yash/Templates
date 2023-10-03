#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 2e5 + 5;


int n;
vector<int> adj[N];
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) {
	visited[v] = true;
	for (int u : adj[v]) {
		if (u == par) continue;
		if (visited[u]) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
		parent[u] = v;
		if (dfs(u, parent[u]))
			return true;
	}
	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	visited.assign(n, false);
	parent.assign(n, -1);
	cycle_start = -1;

	for (int v = 0; v < n; v++) {
		if (!visited[v] && dfs(v, parent[v]))
			break;
	}

	if (cycle_start == -1) {
		cout << "Acyclic" << endl;
	} else {
		vector<int> cycle;
		cycle.push_back(cycle_start);
		for (int v = cycle_end; v != cycle_start; v = parent[v])
			cycle.push_back(v);
		cycle.push_back(cycle_start);
		reverse(cycle.begin(), cycle.end());

		cout << "Cycle found: ";
		for (int v : cycle)
			cout << v << " ";
	}
	return 0;
}