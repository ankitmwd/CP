#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 1e9 + 7;
int dfs(int Node, vector<vector<int>> &Adj, int n, vector<int> &dp)
{
    if (Node == n)
        return 1;
    int sum = 0;
    if (dp[Node] != -1)
        return dp[Node];
    for (auto Adjacent : Adj[Node])
    {
        (sum += dfs(Adjacent, Adj, n, dp)) % M;
    }
    return dp[Node] = sum % M;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
    }
    vector<int> dp(n + 1, -1);
    cout << dfs(1, Adj, n, dp);
}