#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> ans;
int Node1 = -1;
bool dfs(int Node, int Par, vector<vector<int>> &Adj, vector<int> &vis, vector<int> &path, vector<int> &trace)
{
    vis[Node] = 1;
    path[Node] = 1;
    for (auto x : Adj[Node])
    {
        trace[x] = Node;
        if (!vis[x])
        {
            if (dfs(x, Node, Adj, vis, path, trace))
            {
                return true;
            }
        }
        else if (path[x] && Node != Par)
        {
            Node1 = x;
            // trace[x] = Node;
            return true;
        }
    }
    path[Node] = 0;
    return false;
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
    vector<int> vis(n + 1, 0);
    vector<int> trace(n + 1), path(n + 1, 0);
    for (int i = 0; i <= n; i++)
        trace[i] = i;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && Adj[i].size())
        {
            dfs(i, i, Adj, vis, path, trace);
            if (Node1 != -1)
                break;
        }
    }

    if (Node1 == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    // cout << Node1 << endl;
    int x = Node1;
    while (1)
    {
        ans.push_back(Node1);
        if (Node1 == x && ans.size() > 1)
            break;
        Node1 = trace[Node1];
    }
    // ans.pop_back();
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << " ";
    }
}