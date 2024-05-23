#include <bits/stdc++.h>
using namespace std;
#define int long long int
int is_loop(int Node, vector<int> &vis, vector<int> Adj[])
{
    vis[Node] = 1;

    for (auto child : Adj[Node])
    {
        if (vis[child] == 0)
        {
            return is_loop(child, vis, Adj) + 1;
        }
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> Adj[n + 1];
    int sign = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            sign = 1;
        mp[x]++;
        mp[y]++;
        Adj[x].push_back(y);
        Adj[y].push_back(x);

        if (mp[x] > 2 || mp[y] > 2)
            sign = 1;
    }
    if (sign)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (is_loop(i, vis, Adj) % 2 == 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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