#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, 1, 0, -1};
vector<int> edges[N];
bool vis[N];
int col[N];

bool dfs(int v, int c)
{
	vis[v] = true;
	col[v] = c;
	for (int e : edges[v])
	{
		if (!vis[e])
		{
			if (dfs(e, c ^ 1) == false)return false;
		}
		else if (col[e] == col[v])return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}