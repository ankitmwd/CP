#include <bits/stdc++.h>
using namespace std;
#define int long long int
class Disjoint
{
    vector<int> parent;
    vector<int> size;

public:
    Disjoint(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int Upar(int u)
    {
        if (u == parent[u])
            return u;
        else
            return parent[u] = Upar(parent[u]);
    }
    void UnionBysize(int u, int v)
    {
        u = Upar(u);
        v = Upar(v);
        if (u == v)
            return;
        if (size[u] > size[v])
        {
            size[u] += size[v];
            parent[v] = u;
        }
        else
        {
            size[v] += size[u];
            parent[u] = v;
        }
    }
};
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edge.push_back({wt, u, v});
    }
    sort(edge.begin(), edge.end());
    int cst = 0;
    Disjoint ds(n + 1);
    for (int i = 0; i < m; i++)
    {
        int wt = edge[i][0];
        int u = edge[i][1];
        int v = edge[i][2];
        if (ds.Upar(u) != ds.Upar(v))
        {
            cst += wt;
            ds.UnionBysize(u, v);
        }
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(ds.Upar(i));
        if (st.size() >= 2)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout<<cst;
}