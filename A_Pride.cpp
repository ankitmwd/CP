#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sign1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
            sign1++;
    }
    if (sign1 > 0)
    {
        cout << n - sign1 << endl;
        return;
    }
    int cnt = 0;
    int mn = 1e12;
    for (int l = 0; l < n; l++)
    {
        int gd = v[l];
        for (int h = l + 1; h < n; h++)
        {
            gd = __gcd(gd, v[h]);
            if (gd == 1)
            {
                mn = min(h - l, mn);
                break;
            }
        }
    }
    if (mn >= 1e10)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mn + n - 1 << endl;
    }
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}