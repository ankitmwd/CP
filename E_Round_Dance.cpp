#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool fun(int Node, int child, vector<int> &vis, vector<int> Adj[])
{
    vis[Node] = 1;
    for (auto x : Adj[Node])
    {
        if (vis[x] == 0)
        {
            fun(x, Node, vis, Adj);
        }
        else if (vis[x] && x != child)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> vis(n + 1, 0), v(n + 1, 0);
    vector<int> Adj[n + 1];
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (st.find({min(i, v[i]), max(i, v[i])}) != st.end())
        {
        }
        else
        {
            st.insert({min(i, v[i]), max(i, v[i])});
            Adj[i].push_back(v[i]);
            Adj[v[i]].push_back(i);
        }
    }
    int cycle = 0, nonCycle = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            mx++;
            if (fun(i, -1, vis, Adj))
                cycle++;
            else
                nonCycle = 1;
        }
    }
    cout << cycle + nonCycle << " " << mx << endl;
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