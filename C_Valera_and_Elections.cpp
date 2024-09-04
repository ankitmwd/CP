#include <bits/stdc++.h>
using namespace std;
#define int long long int
void dfs(int Node, int par, vector<vector<int>> &Adj, vector<int> &white, vector<int> &dp)
{
    if (white[Node])
    {
        dp[Node] = 1;
    }
    for (auto x : Adj[Node])
    {
        if (x != par)
        {
            dfs(x, Node, Adj, white, dp);
            dp[Node] += dp[x];
        }
    }
}
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> Adj(n + 1);
    vector<int> white(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, dm;
        cin >> x >> y >> dm;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
        if (dm == 2)
        {
            white[y] = 1;
            white[x] = 1;
        }
    }
    vector<int> dp(n + 1, 0);
    dfs(1, 0, Adj, white, dp);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1)
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}