#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int cnt = 1;
    int prev_sc = 1;
    int prev_fs = v[0].first;
    for (int i = 1; i < n; i++)
    {
        int lcm = (v[i].second * prev_sc) / __gcd(v[i].second, prev_sc);
        int mt = (prev_fs * prev_sc) % lcm == 0 && (v[i].first * v[i].second) % lcm == 0;
        int gd = __gcd((prev_fs * prev_sc) / lcm, (v[i].first * v[i].second) / lcm);
        if (mt)
        {
            prev_sc = lcm;
            prev_fs = gd;
        }
        else
        {
            cnt++;
            prev_sc = v[i].second;
            prev_fs = v[i].first;
        }
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