#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1, 0);
    vector<int> vis(n + 1, 0);
    int l = 1;
    int r = 2;
    int cnt = 0;
    while (r <= n)
    {
        while (vis[l])
            l++;
        if (l == r)
            r++;
        cout << "! " << l << " " << r << endl;
        int x;
        cin >> x;
        cout.flush();
        cout << "! " << r << " " << l << endl;
        cout.flush();
        int y;
        cin >> y;
        if (x > y)
        {
            ans[l] = x;
            vis[l] = 1;
            l++;
        }
        else
        {
            ans[r] = y;
            vis[r] = 1;
            r++;
        }
    }
    int xr = 0;
    for (int i = 1; i <= n; i++)
    {
        xr ^= i;
        xr ^= ans[i];
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            ans[i] = xr;
        }
        cout << ans[i] << " ";
    }
    cout.flush();
}
signed main()
{

    solve();
}