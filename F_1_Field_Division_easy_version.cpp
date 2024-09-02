#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    map<int, int> mp, mp2, ans, mp3;
    map<int, vector<int>> mp4;
    vector<pair<int, int>> m1;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        int x1 = -x;
        m1.push_back({x, y});
        if (mp[x] == 0)
        {
            mp[x] = y;
            mp3[x1] = y;
        }
        else
        {
            mp[x] = min(mp[x], y);
            mp3[x1] = min(mp3[x1], y);
        }
        mp4[x].push_back(y);
    }
    mp[0] = 0;
    if (mp[n] == 0)
        mp[n] = m + 1;
    vector<pair<int, int>> m2;
    for (auto x : mp)
    {
        m2.push_back({x.first, x.second});
    }
    reverse(m2.begin(), m2.end());
    int area = 0;
    int mn = m + 1, mn2 = m + 1;
    for (int i = 0; i < m2.size() - 1; i++)
    {
        mn = min(mn, m2[i].second);
        if (mn2 > mn)
        {
            ans[m2[i].first] = 1;
            mn2 = mn;
        }
        else
        {
            ans[m2[i].first] = 0;
        }
        mp2[m2[i].first] = mn;
        area += (m2[i].first - m2[i + 1].first) * (mn - 1);
    }
    mp3[0] = 0;
    mp2[n + 1] = m + 1;
    cout << area << endl;
    for (auto x : m1)
    {
        if (ans[x.first] == 1 && mp2[x.first] == x.second)
        {
            // Line Area of X
            auto it = mp2.upper_bound(x.first);
            int extra = it->second - x.second;
            if (mp4[x.first].size() >= 2)
            {
                sort(mp4[x.first].begin(), mp4[x.first].end());
                extra = min(extra, mp4[x.first][1] - x.second);
            }

            // cout << extra << " ";
            // Upper Area of x
            auto it2 = mp3.upper_bound(-x.first);
            int mn_btw = min(it->second, it2->second);
            int ele_diff = abs(x.first + it2->first) - 1;
            int ex1 = 0;
            ex1 = ele_diff * (it->second - 1) - (ele_diff) * (it2->second - 1);
            // Lower Number
            int lw_min = mp[-it2->first];
            if (mp4[-it2->first].size() >= 2)
            {
                sort(mp4[-it2->first].begin(), mp4[-it2->first].end());
                lw_min = min(lw_min, mp4[-it2->first][1]);
            }
            lw_min = min(lw_min, it->second);
            if (lw_min > x.second)
            {
                ex1 += lw_min - x.second;
            }
            cout << max(ex1 + extra, 1LL) << " ";
        }
        else
        {
            cout << "0" << " ";
        }
    }
    cout << endl;
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