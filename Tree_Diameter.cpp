#include <bits/stdc++.h>
using namespace std;
#define int long long int
int mx = 0;
int fun(int Node, vector<vector<int>> &Adj, vector<int> &sz)
{
    int left = 0, right = 0;
    if (Adj[Node].size() == 0)
        return 1;
    if (Adj[Node].size() > 0)
    {
        left = max(left, fun(Adj[Node][0], Adj, sz));
    }
    if (Adj[Node].size() > 1)
    {
        right = max(right, fun(Adj[Node][1], Adj, sz));
    }
    mx = max(mx, left + right + 1);
    return max(left, right) + 1;
}

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> Adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[x].push_back(y);
    }
    vector<int> sz(n + 1, 0);
    fun(1, Adj, sz);
    cout << mx << endl;
}
