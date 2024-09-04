#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int Node, int par, vector<vector<int>> &Adj, vector<int> &v, int mx, int pos)
{
    if (mx == 0)
        return 0;
    int sum = 0;
    int f = 0;
    for (auto x : Adj[Node])
    {
        if (x != par)
        {
            f = 1;
            if (v[x])
                sum += fun(x, Node, Adj, v, mx - 1, pos);
            else
                sum += fun(x, Node, Adj, v, pos, pos);
        }
    }
    if(f==0) return 1;
    return sum;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> Adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    int dec = 0;
    if (v[1] == 1)
    {
        dec = 1;
    }
    vector<int> vis(n + 1, 0);
    cout << fun(1, -1, Adj, v, m + 1 - dec, m + 1);
}