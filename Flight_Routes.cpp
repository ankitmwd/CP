#include <bits/stdc++.h>
using namespace std;
#define int long long int
void Dij(vector<vector<pair<int, int>>> &Adj, int k)
{
    int n = Adj.size() - 1;
    vector<vector<int>> dis(n + 1, vector<int>(k, 1e15));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int Node = pq.top().second;
        pq.pop();
        if (dis[Node][k - 1] < wt)
            continue;
        for (auto x : Adj[Node])
        {
            if (dis[x.first][k - 1] > wt + x.second)
            {
                dis[x.first][k - 1] = wt + x.second;
                pq.push({dis[x.first][k - 1], x.first});
                sort(dis[x.first].begin(), dis[x.first].end());
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << dis[n][i] << " ";
    }
}
signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> Adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        Adj[u].push_back({v, wt});
    }
    Dij(Adj, k);
}