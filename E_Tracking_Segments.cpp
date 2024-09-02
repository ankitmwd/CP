#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int q;
    cin >> q;
    vector<int> pos;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        pos.push_back(x);
    }
    int l = 0;
    int h = q;
    int ans = -1;
    while (h >= l)
    {
        int sign = 0;
        int mid = (h + l) / 2;
        vector<int> pre(n, 0);
        for (int i = 0; i < mid; i++)
        {
            pre[pos[i] - 1] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            pre[i] += pre[i - 1];
        }
        for (int i = 0; i < m; i++)
        {
            int x = v[i].first;
            int y = v[i].second;
            y--;
            x--;
            int req = (y - x + 1) / 2 + 1;
            int left = 0;
            if (x - 1 >= 0)
            {
                left = pre[x - 1];
            }
            if (pre[y] - left >= req)
            {
                ans = mid;
                sign = 1;
            }
        }
        if (sign)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
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