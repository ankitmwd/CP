#include <bits/stdc++.h>
using namespace std;
#define int long long int
class Disjoint
{
public:
    vector<int> par, sz;
    Disjoint(int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }
    int find_par(int Node)
    {
        if (Node == par[Node])
        {
            return Node;
        }
        return par[Node] = find_par(par[Node]);
    }
    void Union_sz(int u, int v)
    {
        u = find_par(u);
        v = find_par(v);
        if (u == v)
            return;
        if (sz[u] > sz[v])
        {
            sz[u] += sz[v];
            par[v] = u;
        }
        else
        {
            sz[v] += sz[u];
            par[u] = v;
        }
    }
    int size_tree(int u)
    {
        u = find_par(u);
        return sz[u];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    Disjoint ds(n * m + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int rw[] = {1, -1, 0, 0};
    int cl[] = {0, 0, -1, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + rw[k];
                    int nc = j + cl[k];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && v[nr][nc] == '#')
                    {
                        ds.Union_sz(i * m + j, nr * m + nc);
                    }
                }
            }
        }
    }
    int mx = 0;
    for (int j = 0; j < m; j++)
    {
        set<int> st;
        int temp = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (j - 1 >= 0 && v[i][j - 1] == '#')
            {

                int x = ds.find_par((i)*m + j - 1);
                // cout << " Parent : " << x << endl;
                if (st.find(x) == st.end())
                {
                    // cout << " I am Inside " << endl;
                    temp += ds.size_tree((i)*m + j - 1);
                    st.insert(x);
                }
            }
            if (j + 1 < m && v[i][j + 1] == '#')
            {
                // cout << " I am at J+1" << endl;
                int x = ds.find_par((i)*m + j + 1);
                if (st.find(x) == st.end())
                {
                    temp += ds.size_tree((i)*m + j + 1);
                    st.insert(x);
                }
            }
            if (v[i][j] == '#')
            {
                int x = ds.find_par(i * m + j);
                // cout << " Parent 2 : " << x << endl;
                if (st.find(x) == st.end())
                {
                    // cout << " I am inside" << endl;
                    temp += ds.size_tree(i * m + j);
                    st.insert(x);
                }
            }
            if (v[i][j] != '#')
            {
                cnt++;
            }
            // cout << i << " " << temp << endl;
        }
        mx = max(mx, temp + cnt);
    }

    // second
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        int temp = 0;
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (i - 1 >= 0 && v[i - 1][j] == '#')
            {

                int x = ds.find_par((i - 1) * m + j);
                // cout << " Parent : " << x << endl;
                if (st.find(x) == st.end())
                {
                    // cout << " I am Inside " << endl;
                    temp += ds.size_tree((i - 1) * m + j);
                    st.insert(x);
                }
            }
            if (i + 1 < n && v[i + 1][j] == '#')
            {
                // cout << " I am at J+1" << endl;
                int x = ds.find_par((i + 1) * m + j);
                if (st.find(x) == st.end())
                {
                    temp += ds.size_tree((i + 1) * m + j);
                    st.insert(x);
                }
            }
            if (v[i][j] == '#')
            {
                int x = ds.find_par(i * m + j);
                // cout << " Parent 2 : " << x << endl;
                if (st.find(x) == st.end())
                {
                    // cout << " I am inside" << endl;
                    temp += ds.size_tree(i * m + j);
                    st.insert(x);
                }
            }
            if (v[i][j] != '#')
            {
                cnt++;
            }
        }
        mx = max(mx, temp + cnt);
    }
    cout << mx << endl;
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