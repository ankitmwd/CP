#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int sum = 0;
    int lw = 0;
    int cnt = 0;
    int mn = 1e12;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        while (sum > r)
        {
            sum -= v[lw];
            lw++;
        }
        // cout << sum << endl;
        if (sum >= l)
        {
            cnt++;
            sum = 0;
            lw = i + 1;
        }
        // cout << i << " " << cnt << " " << sum << endl;
    }
    cout << cnt << endl;
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