#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool dfs(vector<int> &prem, vector<vector<int>> &Adj)
{
    int n = prem.size() - 1;
    vector<int> vis(n + 1, 0);
    set<int> st;
    st.insert(1);
    int cnt = 1;
    while (!st.empty())
    {
        if (st.find(prem[cnt]) == st.end())
        {
            return 0;
        }

        int Node = prem[cnt];
        st.erase(st.find(Node));
        vis[Node] = 1;
        cnt++;
        for (auto x : Adj[Node])
        {
            if (!vis[x])
            {
                st.insert(x);
            }
        }
    }
    if (cnt == n + 1)
        return true;
    else
        return false;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> Adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        Adj[x].push_back(i + 1);
    }
    vector<int> prem(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> prem[i];
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        swap(prem[x], prem[y]);
        for (int i = 1; i <= n; i++)
        {
            cout << prem[i] << " ";
        }
        cout << endl;
        int ans = dfs(prem, Adj);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
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