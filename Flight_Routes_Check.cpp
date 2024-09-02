#include <bits/stdc++.h>
using namespace std;
#define int long long int
void bfs(int start, vector<int> &vis, vector<vector<int>> &Adj)
{
    queue<int> que;
    que.push(start);
    while (!que.empty())
    {
        int Node = que.front();
        que.pop();
        vis[Node] = 1;
        for (auto Adjacent : Adj[Node])
        {
            if (!vis[Adjacent])
            {
                que.push(Adjacent);
            }
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> Indegree(n + 1, 0), Out(n + 1, 0);
    vector<vector<int>> Adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Indegree[u]++;
        Out[v]++;
    }
    int mn_ind = 1;
    int ind = n;
    for (int i = 1; i <= n; i++)
    {
        if (Indegree[i] == 0)
        {
            cout << "NO" << endl;
            cout << i << " " << (i + 1) % n << endl;
            return 0;
        }
        if (Out[i] < ind)
        {
            ind = Out[i];
            mn_ind = i;
        }
    }
    vector<int> vis(n + 1, 0);
    bfs(mn_ind, vis, Adj);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            cout << "NO" << endl;
            cout << mn_ind << " " << i << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}