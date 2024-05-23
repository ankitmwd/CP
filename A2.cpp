#include <bits/stdc++.h>
using namespace std;
void fun(int Node, vector<int> &vis, vector<int> Adj[])
{
    vis[Node] = 1;
    for (auto Child : Adj[Node])
    {
        if (vis[Child] == 0)
        {
            fun(Child, vis, Adj);
        }
    }
    return;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> Adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    int ans = 0;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            ans++;
            fun(i, vis, Adj);
        }
    }
    cout << ans << endl;
    return 0;
}