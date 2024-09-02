#include <bits/stdc++.h>
using namespace std;
#define int long long int
void bfs(int start, vector<int> &vis, vector<int> &ans, vector<vector<int>> &Adj)
{
    queue<int> que;
    que.push(start);
    set<int> st;
    while (!que.empty())
    {
        int Node = que.front();
        vis[Node] = 1;
        st.insert(Node);
        que.pop();
        for (auto x : Adj[Node])
        {
            if (!vis[x])
            {
                que.push(x);
            }
        }
    }
    int sz = st.size();
    for (auto x : st)
    {
        ans[x] = sz;
    }
    return;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        vector<int> temp;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            temp.push_back(y);
        }
        for (int j = 1; j < temp.size(); j++)
        {
            Adj[temp[j - 1]].push_back(temp[j]);
            Adj[temp[j]].push_back(temp[j - 1]);
        }
    }
    vector<int> vis(n + 1, 0);
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            bfs(i, vis, ans, Adj);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}