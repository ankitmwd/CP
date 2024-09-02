#include <bits/stdc++.h>
using namespace std;
#define int long long int
int mn_dis = 1e15;
int mn_cnt = 0;
int mn_flight = 1e8;
int mx_flight = 0;
void Dijisktra(int Node, vector<vector<pair<int, int>>> &Adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    int n = Adj.size() - 1;
    vector<int> dis(n + 1, 1e15);
    dis[Node] = 0;
    while (!pq.empty())
    {
        Node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if (dis[Node] > wt)
            continue;
        for (auto x : Adj[Node])
        {
            int v = x.first;
            int weight = x.second;
            if (dis[v] >= dis[Node] + weight)
            {
                dis[v] = dis[Node] + weight;
                pq.push({dis[v], v});
            }
        }
    }
    mn_dis = dis[n];
}
void Dijisktra1(int Node, vector<vector<pair<int, int>>> &Adj)
{
    queue<vector<int>> que;
    que.push({0, 1, 0, 0});
    int n = Adj.size() - 1;
    vector<int> dis(n + 1, 1e15);
    vector<int> vis(n + 1, 0);
    dis[Node] = 0;
    while (!que.empty())
    {
        auto v = que.front();
        int wt = v[0];
        Node = v[1];
        int mn = v[2];
        int mx = v[3];
        que.pop();
        if (dis[Node] > wt && wt > mn_dis)
            continue;
        if (Node == n && dis[Node] == mn_dis && wt == mn_dis)
        {
            mn_flight = min(mn_flight, mn);
            mx_flight = max(mx, mx_flight);
            mn_cnt++;
        }
        for (auto x : Adj[Node])
        {
            auto v1 = x.first;
            int weight = x.second;
            if (dis[v1] >= wt + weight && wt + weight <= mn_dis)
            {
                dis[v1] = wt + weight;
                que.push({dis[v1], v1, mn + 1, mx + 1});
            }
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> Adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        Adj[u].push_back({v, wt});
    }
    Dijisktra(1, Adj);
    Dijisktra1(1, Adj);
    cout << mn_dis << " " << mn_cnt << " " << mn_flight << " " << mx_flight << endl;
}