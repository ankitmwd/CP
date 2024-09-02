#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> Adj(n + 1);
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
        Adj[u].push_back({v, wt});
    }
    vector<int> dis(n + 1, 0);
    vector<int> path(n + 1);
    for (int i = 0; i <= n; i++)
    {
        path[i] = i;
    }
    int x1 = 0;
    int Node = 1;
    for (int i = 0; i < n; i++)
    {
        x1 = -1;
        for (auto x : edges)
        {
            int v = x[0];
            int u = x[1];
            int wt = x[2];
            if (dis[u] > dis[v] + wt)
            {
                dis[u] = dis[v] + wt;
                path[u] = v;
                Node = u;
                x1 = 1;
            }
        }
    }
    if (x1 == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            Node = path[Node];
            // cout << Node << " " << path[Node] << endl;
        }
        vector<int> ans;
        for (int v = Node;; v = path[v])
        {
            ans.push_back(v);
            if (v == Node && ans.size() > 1)
                break;
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}
signed main()
{

    solve();
}