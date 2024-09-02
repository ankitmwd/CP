#include <bits/stdc++.h>
using namespace std;
#define int long long int
void fun(int Node, int par, vector<vector<int>> &Adj, vector<int> &sz)
{
    for (auto x : Adj[Node])
    {
        if (x != par)
        {
            fun(x, Node, Adj, sz);
            sz[Node] += sz[x] + 1;
        }
    }
}
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> Adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        Adj[x].push_back(i + 1);
    }
    vector<int> sz(n + 1, 0);
    fun(1, -1, Adj, sz);
    for (int i = 1; i <= n; i++)
    {
        cout << sz[i]<< " ";
    }
}