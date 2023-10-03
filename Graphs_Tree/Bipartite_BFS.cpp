#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
vector<int> edges[N];
bool vis[N];
int col[N];

bool bfs(int v) {
	queue<int> q;
	vis[v] = 1;
	col[v] = 1;
	q.push(v);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int e : edges[cur])
			if (vis[e] == false)
			{
				vis[e] = true;
				col[e] = col[cur] ^ 1;
				q.push(e);
			}
			else if (col[cur] == col[e])
			{
				return false;
			}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}