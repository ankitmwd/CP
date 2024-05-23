#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int xr1 = 0, xr2 = 0;
    for (int i = 0; i < n; i++)
    {
        xr1 ^= v[i];
        xr2 = 0;
        int cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            xr2 ^= v[j];
            if (xr2 == xr1)
            {
                cnt++;
                xr2 = 0;
            }
        }
        if (xr2 == 0 && cnt >= 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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