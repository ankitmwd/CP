#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(vector<int> Adj[], vector<int> vis1, vector<int> vis2, int start, int end)
{
    queue<int> q1, q2;
    q1.push(start);
    q2.push(end);
    set<int> st;
    st.insert(start);
    st.insert(end);
    int dis = 1;
    if (start == end)
        return start;
    while (!q1.empty() && !q2.empty())
    {
        int x = q1.front();
        int y = q2.front();
        vis1[x] = 1;
        vis2[y] = 1;
        q1.pop();
        q2.pop();
        for (auto child : Adj[x])
        {
            if (vis1[child] == 0)
            {
                q1.push(child);
                st.insert(child);
            }
        }
        for (auto child : Adj[y])
        {
            if (vis2[child] == 0)
            {
                q2.push(child);
                int x1 = st.size();
                st.insert(child);
                int x2 = st.size();
                if (x1 == x2)
                    return child;
            }
        }
    }
}
int fun2(int Node, vector<int> vis, vector<int> Adj[])
{
    queue<pair<int, int>> q1;
    q1.push({Node, 0});
    int mx = 0;
    while (!q1.empty())
    {
        int x = q1.front().first;
        int dis = q1.front().second;
        vis[x] = 1;
        mx = max(mx, dis);
        q1.pop();
        for (auto child : Adj[x])
        {
            if (vis[child] == 0)
            {
                q1.push({child, dis + 1});
            }
        }
    }
    return mx;
}
int fun3(vector<int> Adj[], vector<int> &vis, int end, int cm)
{

    queue<pair<int, int>> que;
    que.push({end, 0});
    while (!que.empty())
    {
        int x = que.front().first;
        int dis = que.front().second;
        if (x == cm)
            return dis;
        que.pop();
        vis[x] = 1;
        for (auto child : Adj[x])
        {
            if (vis[child] == 0)
            {
                que.push({child, dis + 1});
            }
        }
    }
}
vector<int> dfs(int start, int p, int end, vector<int> Adj[])
{
    if (start == end)
        return {start};
    for (auto e : Adj[start])
    {
        if (e != p)
        {
            vector<int> v = dfs(e, start, end, Adj);
            if (v.size())
            {
                v.push_back(start);
                return v;
            }
        }
    }
    return {};
}
void solve()
{
    int n;
    cin >> n;
    vector<int> Adj[n + 1];
    int start, end;
    cin >> start >> end;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    vector<int> vis3(n + 1, 0);
    vector<int> vis4(n + 1, 0);
    // int cm = fun(Adj, vis1, vis2, start, end);
    vector<int> path = dfs(start, 0, end, Adj);
    reverse(path.begin(), path.end());
    int dis_bw = path.size();
    int cm = path[(dis_bw + 1) / 2 - 1];
    int mx_dis = fun2(cm, vis3, Adj);
    // int dis_bw = fun3(Adj, vis4, end, cm);
    // cout << cm << " " << dis_bw / 2 << endl;

    cout << 2 * (n - 1) + dis_bw / 2 - mx_dis << endl;
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