#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
}
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> Adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    Adj[1].push_back(1);
    vector<int> vis(n + 1, 0);
    double sum = 0;
    queue<pair<int, double>> que;
    que.push({1, 1});
    while (!que.empty())
    {
        int Node = que.front().first;
        double dis = que.front().second;
        vis[Node] = 1;
        que.pop();
        for (auto x : Adj[Node])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                double sz = Adj[Node].size() - 1;
                sum += (dis / sz);
                que.push({x, dis / sz});
            }
        }
    }
    cout << setprecision(20) << sum << endl;
}