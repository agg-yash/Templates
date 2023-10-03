#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, 1, 0, -1};
vector<int> edges[N];
bool vis[N];
int in[N], out[N];

int timer = 1;
void dfs(int v)
{
	vis[v] = true;
	in[v] = timer++;
	for (int e : edges[v])
	{
		if (!vis[e])dfs(e);
	}
	out[v] = timer++;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}