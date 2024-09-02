#include <bits/stdc++.h>
using namespace std;
#define int long long int
void fun(int Node, vector<int> &vis, vector<int> Adj[])
{
    set<int> pq;
    pq.insert(1);
    while (!pq.empty())
    {
        int x = *pq.begin();
        if (vis[x] == 0)
            cout << x << " ";
        vis[x] = 1;
        pq.erase(x);
        for (auto Neig : Adj[x])
        {
            if (vis[Neig] == 0)
            {
                pq.insert(Neig);
            }
        }
    }
}
void solve()
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
    vector<int> vis(n + 1, 0);
    fun(1, vis, Adj);
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}