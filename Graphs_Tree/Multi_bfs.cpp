#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
bool vis[N];
int lev[N];
int bfs()
{

	queue<array<int, 2>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == mx) // push all the sources u want
			{
				q.push({i, j});
				vis[i] = true;
				lev[i] = 0;
			}
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int new = cur + dx[i];
			if (!isvalid(new))continue;
			q.push({newx, newy});
			vis[newx][newy] = true;
			lev[newx][newy] = lev[curx][cury] + 1;
			ans = max(ans, lev[newx][newy]);
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}