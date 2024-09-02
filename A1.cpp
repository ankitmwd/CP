#include <bits/stdc++.h>
using namespace std;
int fun(int start, int end, vector<int> &vis, vector<int> Adj[])
{
    queue<pair<int, int>> que;
    que.push({start, 0});
    while (!que.empty())
    {
        int Node = que.front().first;
        int step = que.front().second;
        vis[Node] = 1;
        if (Node == end)
            return step;
        que.pop();
        for (auto child : Adj[Node])
        {
            if (vis[child] == 0)
            {
                vis[child] = 1;
                que.push({child, step + 1});
            }
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> Adj[n + 1];
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    cin >> x >> y;
    vector<int> vis(n + 1, 0);
    int ans = fun(x, y, vis, Adj);
    cout << (ans == -1 ? 0 : ans) << endl;
}
