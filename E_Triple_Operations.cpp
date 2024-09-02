#include <bits/stdc++.h>
using namespace std;
#define int long long int
int m = 1e2;
vector<int> pref(m, 0);
void solve()
{
    int l, r;
    cin >> l >> r;
    int low_cnt = 0, high_cnt = 0;
    int x = l, y = r;
    while (x)
    {
        x = x / 3;
        low_cnt++;
    }
    while (y)
    {
        y = y / 3;
        high_cnt++;
    }
    if (low_cnt == high_cnt)
    {
        cout << (r - l + 2) * (low_cnt) << endl;
    }
    else
    {
        int ans = low_cnt;
        int prev = l;
        for (int i = low_cnt; i <= high_cnt; i++)
        {
            int x = pow(3, i);
            x = min(x, r + 1);
            ans += (x - prev) * (i);
            prev = x;
        }
        cout << ans << endl;
    }
}
signed main()
{
    int t;
    cin >> t;
    int cnt = 1;
    while (t--)
    {
        solve();
    }
}
