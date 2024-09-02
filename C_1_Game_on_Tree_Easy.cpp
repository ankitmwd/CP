#include <bits/stdc++.h>
using namespace std;
#define int long long int
void dfs(int Node, int par, vector<int> &cnt, vector<vector<int>> &Adj)
{
    cnt[Node] = 0;
    for (auto x : Adj[Node])
    {
        if (x != par)
        {
            dfs(x, Node, cnt, Adj);
            cnt[Node] += (cnt[x] + 1);
        }
    }
}
signed main()
{
    int n, t;
    cin >> n >> t;
    vector<vector<int>> Adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    vector<int> cnt(n + 1, 0);
    int Node;
    cin >> Node;
    dfs(Node, -1, cnt, Adj);
    int sign = 1;
    for (auto x : Adj[Node])
    {
        if (cnt[x] % 2 == 0)
            sign = 0;
    }
    if (sign)
    {
        cout << "Hermione" << endl;
    }
    else
    {
        cout << "Ron" << endl;
    }
}