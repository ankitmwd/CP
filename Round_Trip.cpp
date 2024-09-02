#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool bfs(int Node, int Par, vector<int> &vis, vector<vector<int>> &Adj, vector<int> &path)
{
    vis[Node] = 1;
    for (auto child : Adj[Node])
    {
        if (vis[child] == 0)
        {
            path.push_back(Node);
            if (bfs(child, Node, vis, Adj, path) == 1)
                return 1;
            else
                path.pop_back();
        }
        else if (vis[child] == 1 && child != Par && Par != -1)
        {
            path.push_back(Node);
            vector<int> path2;
            path2.push_back(child);
            for (int i = path.size() - 1; i >= 0; i--)
            {
                path2.push_back(path[i]);
                if (child == path[i])
                    break;
            }
            cout << path2.size() << endl;
            for (int i = 0; i < path2.size(); i++)
            {
                cout << path2[i] << " ";
            }
            return 1;
        }
    }
    return 0;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Adj(n + 1);
    int v, u;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> u;
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    vector<int> vis(n + 1, 0);
    vector<int> path;
    for (int i = 1; i <= n; i++)
    {
        if (bfs(i, -1, vis, Adj, path))
            return;
    }
    cout << "IMPOSSIBLE" << endl;
}
signed main()
{
    solve();
}