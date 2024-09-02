#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> Indegree(n + 1, 0);
    vector<int> Adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Indegree[v]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if (Indegree[i] == 0)
        {
            que.push(i);
        }
    }
    vector<int> ans;
    while (!que.empty())
    {
        int Node = que.front();
        ans.push_back(Node);
        que.pop();
        for (auto Adjacent : Adj[Node])
        {
            Indegree[Adjacent]--;
            if (Indegree[Adjacent] == 0)
            {
                que.push(Adjacent);
            }
        }
    }
    if (ans.size() == n)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}