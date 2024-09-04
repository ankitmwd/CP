#include <bits/stdc++.h>
using namespace std;
#define int long long int
class DisJoint
{
public:
    vector<int> par, size;
    DisJoint(int n)
    {
        par.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }
    int upar(int v)
    {
        if (v == par[v])
            return v;
        else
            return par[v] = upar(par[v]);
    }
    void join(int u, int v)
    {
        v = upar(v);
        u = upar(u);
        if (v == u)
            return;
        if (size[v] > size[u])
        {
            size[v] += size[u];
            par[u] = v;
        }
        else
        {
            size[u] += size[v];
            par[v] = u;
        }
    }
};
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    DisJoint ds(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.')
            {
                if (i - 1 >= 0 && v[i - 1][j] == '.')
                {
                    int v = i * m + j;
                    int u = (i - 1) * m + j;
                    ds.join(v, u);
                }
                if (j - 1 >= 0 && v[i][j - 1] == '.')
                {
                    int v = i * m + j;
                    int u = (i)*m + j - 1;
                    ds.join(v, u);
                }
                if (i + 1 < n && v[i + 1][j] == '.')
                {
                    int v = i * m + j;
                    int u = (i + 1) * m + j;
                    ds.join(v, u);
                }
                if (j + 1 < m && v[i][j + 1] == '.')
                {
                    int v = i * m + j;
                    int u = (i)*m + j + 1;
                    ds.join(v, u);
                }
            }
        }
    }
    vector<string> ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '*')
            {
                set<int> st;

                if (i - 1 >= 0 && v[i - 1][j] == '.')
                {
                    int u = (i - 1) * m + j;
                    st.insert(ds.upar(u));
                }
                if (j - 1 >= 0 && v[i][j - 1] == '.')
                {

                    int u = (i)*m + j - 1;
                    st.insert(ds.upar(u));
                }
                if (i + 1 < n && v[i + 1][j] == '.')
                {

                    int u = (i + 1) * m + j;
                    st.insert(ds.upar(u));
                }
                if (j + 1 < m && v[i][j + 1] == '.')
                {

                    int u = (i)*m + j + 1;
                    st.insert(ds.upar(u));
                }
                int num = 1;
                for (auto x : st)
                {
                    num += ds.size[x];
                }
                num = num % 10;
                string str = to_string(num);
                ans[i] += str;
            }
            else
            {
                ans[i] += '.';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}