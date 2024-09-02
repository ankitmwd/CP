#include <bits/stdc++.h>
using namespace std;
class Disjoint
{
    vector<int> par;
    vector<int> rank;
    vector<int> sz;

public:
    Disjoint(int n)
    {
        par.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }
    void union_by_rank(int u, int v)
    {
        u = find_par(u);
        v = find_par(v);
        if (u == v)
            return;
        if (rank[u] > rank[v])
        {
            par[v] = u;
        }
        else if (rank[u] < rank[v])
        {
            par[u] = v;
        }
        else
        {
            par[u] = v;
            rank[u]++;
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
    void union_by_sz(int u, int v)
    {
        u = find_par(u);
        v = find_par(v);
        if (u == v)
            return;
        if (sz[u] > sz[v])
        {
            par[v] = u;
            sz[u] += sz[v];
        }
        else
        {
            par[u] = v;
            sz[v] += sz[u];
        }
    }
};
int main()
{
    Disjoint ds(7);
    ds.union_by_sz(1, 2);
    ds.union_by_sz(2, 3);
    ds.union_by_sz(4, 5);
    ds.union_by_sz(6, 7);
    ds.union_by_sz(5, 6);
    if (ds.find_par(3) == ds.find_par(7))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not same" << endl;
    }
    ds.union_by_sz(3, 7);
    if (ds.find_par(3) == ds.find_par(7))
    {
        cout << "Same" << endl;
    }
}