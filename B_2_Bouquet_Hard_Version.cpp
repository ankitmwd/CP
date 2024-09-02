#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    vector<pair<int, int>> v1;
    for (int i = 0; i < n; i++)
    {
        v1.push_back({v[i], val[i]});
    }
    sort(v1.begin(), v1.end());
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v1[i].first * v1[i].second > k)
        {
            mx = max(mx, k - (k % v1[i].first));
        }
        else
        {
            mx = max(mx, v1[i].first * v1[i].second);
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (v1[i].first - v1[i - 1].first <= 1)
        {
            int total = v1[i].first * v1[i].second + v1[i - 1].first * v1[i - 1].second;
            if (total <= k)
            {
                mx = max(mx, total);
            }
            else
            {
                
            }
        }
    }
    cout << mx << endl;
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