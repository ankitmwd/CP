#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool fun(int Node, vector<int> Adj[], vector<int> &vis, int Gaol)
{
    bool ans = false;
    if (Node >= Gaol)
    {
        // cout << "true" << endl;
        return true;
    }
    vis[Node] = 1;
    for (auto Child : Adj[Node])
    {
        // cout << Child << endl;
        if (vis[Child] == 0)
        {
            ans |= fun(Child, Adj, vis, Gaol);
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    // vector<int> Adj[n + 2];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i - v[i] - 1 >= 0 && dp[i - v[i] - 1])
            dp[i] = 1;
        if (i + v[i] <= n && dp[i - 1])
            dp[i + v[i]] = 1;
    }
    cout << (dp[n] ? "YES" : "NO") << endl;
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