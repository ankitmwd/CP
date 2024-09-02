#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int i = 0;
    int sign = 1;
    vector<int> vis(n, 0);
    int mn = -1;
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++)
    {
        if (v[i] % v[0] != 0)
        {

            if (mn == -1)
                mn = v[i];
        }
        else
        {
            vis[i] = 1;
        }
    }
    if (mn != -1)
    {
        for (i = 0; i < n; i++)
        {
            if (v[i] % mn != 0)
            {
            }
            else
            {
                vis[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            sign = 0;
    }
    if (sign)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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