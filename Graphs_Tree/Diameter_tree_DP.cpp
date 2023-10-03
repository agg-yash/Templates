#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
vector<int> edges[N];
int ans;
int dp[N][2];
bool isleaf(int u)
{
  if (u != 1 && edges[u].size() == 1)return true;
  return false;
}
void Dfs(int v, int par = -1)
{
  vector<int>childnodes;
  if (isleaf(v)) {
    dp[v][0] = dp[v][1] = 0;
    return;
  }
  for (int e : edges[v])
  {
    if (e == par)continue;
    Dfs(e, v);
    childnodes.push_back(dp[e][0]);
  }
  sort(childnodes.rbegin(), childnodes.rend());
  int children = (int)childnodes.size();
  dp[v][0] = 1 + childnodes[0];
  if (children == 1) {
    dp[v][1] = 0;
  }
  else
  {
    dp[v][1] = 2 + childnodes[0] + childnodes[1];
  }
  ans = max({ans, dp[v][0], dp[v][1]});
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)edges[i].clear(), dp[i][0] = dp[i][1] = 0;
  if (n == 1) {cout << 0; return 0;}
  for (int i = 1; i <= n - 1; i++) {
    int u, v; cin >> u >> v;
    edges[u].push_back(v), edges[v].push_back(u);
  }
  Dfs(1);
  cout << ans;
  return 0;
}