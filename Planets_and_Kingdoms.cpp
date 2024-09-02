#include <bits/stdc++.h>
using namespace std;
#define int long long int
void bfs(int Node, vector<vector<int>> &Adj, vector<int> &vis, vector<int> &id, int idx)
{
    vis[Node] = 1;
    id[Node] = idx;
    for (auto x : Adj[Node])
    {
        if (vis[x] == 0)
        {
            bfs(x, Adj, vis, id, idx);
        }
    }
}
void bfs1(int Node, vector<int> &time, vector<int> &vis, vector<vector<int>> &Adj)
{
    vis[Node] = 1;
    for (auto x : Adj[Node])
    {
        if (!vis[x])
        {
            bfs1(x, time, vis, Adj);
        }
    }
    time.push_back(Node);
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Adj(n + 1), Adj1(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj1[x].push_back(y);
        Adj[y].push_back(x);
    }
    vector<int> time;
    vector<int> vis1(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis1[i] == 0)
            bfs1(i, time, vis1, Adj1);
    }
    reverse(time.begin(), time.end());
    vector<int> id(n + 1, 0);
    vector<int> vis(n + 1, 0);
    int idx = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[time[i]])
        {
            bfs(time[i], Adj, vis, id, idx);
            idx++;
        }
    }
    cout << idx - 1 << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << id[i] << " ";
    }
}