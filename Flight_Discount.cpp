#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> Edges;
void dfs(int Node, vector<vector<pair<int, int>>> &Adj, vector<int> &dis)
{
    dis[Node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, Node});
    int n = Adj.size();
    vector<int> vis(n + 1, 0);
    while (!que.empty())
    {
        int u = que.top().second;
        int WT = que.top().first;
        que.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto x : Adj[u])
        {
            int v = x.first;
            int wt = x.second;
            if (dis[v] > dis[u] + wt)
            {
                dis[v] = dis[u] + wt;
                que.push({dis[v], v});
            }
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> Adj(n + 1), Adj1(n + 1);
    for (int i = 0; i < m; i++)
    {
        int v, u, wt;
        cin >> v >> u >> wt;
        Adj[v].push_back({u, wt});
        Adj1[u].push_back({v, wt});
        Edges.push_back({v, u, wt});
    }
    vector<int> dis(n + 1, 1e15), dis1(n + 1, 1e15);
    dfs(1, Adj, dis);
    dfs(n, Adj1, dis1);
    int mn = 1e16;
    for (auto x : Edges)
    {
        int v = x[0];
        int u = x[1];
        int wt = x[2];
        mn = min(mn, dis[v] + dis1[u] + wt / 2);
    }
    cout << mn << endl;
}