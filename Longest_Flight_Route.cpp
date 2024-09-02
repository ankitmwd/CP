#include <bits/stdc++.h>
using namespace std;
// #define int long long int
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
vector<vector<int>> Adj;
vector<int> dis;
vector<int> path;
signed main()
{
    int n, m;
    cin >> n >> m;
    Adj.resize(n + 1);
    dis.resize(n + 1, 0);
    path.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
    }
    vector<int> vis(n + 1, 0);
    que.push({0, 1});
    while (!que.empty())
    {
        int Node = que.top().second;
        int dis1 = que.top().first;
        que.pop();
        if (dis[Node] > dis1)
            continue;
        for (auto x : Adj[Node])
        {
            if (dis[x] > dis[Node] - 1)
            {
                dis[x] = dis[Node] - 1;
                path[x] = Node;
                que.push({dis[x], x});
            }
        }
    }
    if (dis[n] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> ans;
        while (1)
        {
            ans.push_back(n);
            if (n == 1 && ans.size() > 1)
                break;
            n = path[n];
        }
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}
