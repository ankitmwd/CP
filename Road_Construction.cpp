#include <bits/stdc++.h>
using namespace std;
#define int long long int
class Disjoint
{
public:
    vector<int> size;
    vector<int> parent;
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
    int UnionBySize(int u, int v)
    {
        u = Upar(u);
        v = Upar(v);
        if (u == v)
            return 0;
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
        return max(size[u], size[v]);
    }
};
signed main()
{
    int n, m;
    cin >> n >> m;
    int components = n;
    int mx = 0;
    Disjoint ds(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (ds.Upar(u) != ds.Upar(v))
        {
            components--;
        }
        int x = ds.UnionBySize(u, v);
        mx = max(mx, x);
        cout << components << " " << mx << endl;
    }
}
