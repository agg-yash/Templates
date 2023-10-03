#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 2e5 + 5;

vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
	color[v] = 1;
	for (int u : adj[v]) {
		if (color[u] == 0) {
			parent[u] = v;
			if (dfs(u))
				return true;
		} else if (color[u] == 1) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
	}
	color[v] = 2;
	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	color.assign(n, 0);
	parent.assign(n, -1);
	cycle_start = -1;

	for (int i = 0; i < n; i++) {
		if (color[i] == 0 && dfs(i))
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

		return 0;
	}