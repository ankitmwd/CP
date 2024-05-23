#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    int mn = 1e12, mx = -1e12;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, v1[i] - v2[i]);
        // mn = min(mn, v1[i] + v2[i]);
        // mx = max(mn, v1[i] - v2[i]);
        mx = max(mx, v1[i] + v2[i]);
    }
    // cout << mn + mx << endl;
    int ans = (mn + mx) / 2;
    if ((mn + mx) % 2 == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << ans << ".5" << endl;
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