#include <bits/stdc++.h>
using namespace std;
#define int long long int
void Dijisktra(int Node, vector<int> &dis, vector<vector<pair<int, int>>> &Adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = Adj.size();
    vector<int> vis(n, 0);
    pq.push({0, Node});
    dis[Node] = 0;
    while (!pq.empty())
    {
        Node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if (vis[Node])
            continue;
        vis[Node] = 1;
        for (auto child : Adj[Node])
        {
            int u = child.first;
            int wt = child.second;
            if (dis[u] > dis[Node] + wt)
            {
                dis[u] = dis[Node] + wt;
                pq.push({dis[u], u});
            }
        }
    }
    return;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dis(n + 1, 1e18);
    vector<vector<pair<int, int>>> Adj(n + 1);
    int x, y, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> wt;
        Adj[x].push_back({y, wt});
    }
    Dijisktra(1, dis, Adj);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
}