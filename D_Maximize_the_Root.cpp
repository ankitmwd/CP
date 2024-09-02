#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int Node, vector<int> &v, vector<vector<int>> &Adj, int mn, vector<int> &vis)
{

    vis[Node] = 1;
    for (auto x : Adj[Node])
    {
        if (!vis[x])
        {
            fun(x, v, Adj, mn, vis);
            if (mn == 1e8)
            {
                mn = min(mn, v[x]);
            }
            else if (mn > v[x])
            {
                mn = mn + (mn - v[x]) / 2;
            }
        }
    }
    cout << Node << " " << mn << endl;
    return mn;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> Adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        Adj[x].push_back(i + 2);
    }
    vector<int> vis(n + 1, 0);
    int mn = 1e8;
    int x = fun(1, v, Adj, 1e8, vis);
    cout << x << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}