#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF 1e14
void bfs(int Node, vector<vector<int>> &Adj, vector<int> &vis)
{
    vis[Node] = 1;
    for (auto x : Adj[Node])
    {
        if (!vis[x])
        {
            bfs(x, Adj, vis);
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<vector<int>> Adj1(n + 1), Adj2(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, -wt});
        Adj1[u].push_back(v);
        Adj2[v].push_back(u);
    }
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    bfs(1, Adj1, vis1);
    bfs(n, Adj2, vis2);
    vector<int> dis(n + 1, INF);
    int flag = 0;
    dis[1] = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (auto x : edges)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            if (dis[u] != INF && vis1[v] && vis2[v] && dis[v] > dis[u] + wt)
            {
                flag = 1;
                dis[v] = dis[u] + wt;
            }
        }
    }
    if (flag)
    {
        cout << -1 << endl;
    }
    else
    {
        cout <<-dis[n] << endl;
    }
}