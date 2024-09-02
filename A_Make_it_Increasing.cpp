#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int j = 0; j < n; j++)
    {
        cin >> v[j];
    }
    int ans = 1e18;
    for (int j = 0; j < n; j++)
    {
        int cnt = 0;
        int prev = 0;
        for (int k = j - 1; k >= 0; k--)
        {
            int time = prev / v[k] + 1;
            // cout << time << endl;
            cnt += time;
            prev = time * v[k];
        }
        prev = 0;
        for (int k = j + 1; k < n; k++)
        {
            int time = prev / v[k] + 1;
            // cout << time << endl;
            cnt += time;
            prev = time * v[k];
        }
        ans = min(cnt, ans);
        // cout << cnt << " " << v[j] << " " << j << endl;
    }
    cout << ans << endl;
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