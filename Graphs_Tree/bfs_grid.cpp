#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 40;
const int mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, 1, 0, -1};
vector<int> edges[N];
bool vis[N][N];
char v[N][N];
int dis[N][N];
int n;
bool isvalid(int x, int y) // change accordingly :)
{
	if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
		return false;

	if (vis[x][y] == true || v[x][y] == 'T')return false;
	return true;
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	dis[x][y] = 0;
	q.push({x, y});
	vis[x][y] = true;
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newx = curx + dx[i];
			int newy = cury + dy[i];
			if (isvalid(newx, newy))
			{
				vis[newx][newy] = true;
				q.push({newx, newy});
				dis[newx][newy] = 1 + dis[curx][cury];
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int ex, ey, sx, sy;
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 'E')ex = i, ey = j;
			if (v[i][j] == 'S')sx = i, sy = j;
		}
	}

	bfs(sx, sy);
	cout << dis[ex][ey];
	return 0;
}