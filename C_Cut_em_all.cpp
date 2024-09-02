#include <bits/stdc++.h>
using namespace std;
#define int long long int
int ans = 0;
void dfs(int Node, int par, vector<vector<int>> &Adj, vector<int> &vis)
{
    vis[Node] = 1;
    for (auto x : Adj[Node])
    {
        if (x != par)
        {
            dfs(x, Node, Adj, vis);
            vis[Node] += vis[x];
        }
    }
    if (vis[Node] % 2 == 0 && par != -1)
    {
        ans++;
    }
}
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> Adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    vector<int> vis(n + 1, 0);
    dfs(1, -1, Adj, vis);
    if (n % 2)
    {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;
}