#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;
    map<string, int> dic;
    int cnt = 1;
    map<int, string> v;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        if (dic[str] == 0)
        {
            dic[str] = cnt;
            cnt++;
        }
        mp[dic[str]].push_back(i + 1);
        v[i + 1] = str;
    }
    int sz = mp.size();

    vector<vector<int>> v1(sz);
    for (auto x : mp)
    {
        for (auto y : x.second)
        {
            v1[x.first - 1].push_back(-y);
        }
    }
    for (int i = 0; i < v1.size(); i++)
    {
        sort(v1[i].begin(), v1[i].end());
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int mt = 0;
        for (int i = 0; i < v[x].size(); i++)
        {
            for (int j = 0; j < v[y].size(); j++)
            {
                if (v[x][i] == v[y][j])
                    mt = 1;
            }
        }
        if (mt)
        {
            cout << abs(x - y) << endl;
        }
        else
        {
            int mn = min(x, y);
            int mx = max(x, y);
            int ans = 1e8;
            string nw1 = v[x];
            string nw2 = v[y];
            // cout << nw1 << " " << nw2 << endl;
            for (int i = 0; i < nw1.size(); i++)
            {
                for (int j = 0; j < nw2.size(); j++)
                {
                    string nw0 = "";
                    nw0 += nw1[i];
                    nw0 += nw2[j];
                    sort(nw0.begin(), nw0.end());
                    if (dic[nw0] != 0)
                    {
                        int nw = dic[nw0];
                        auto x1 = lower_bound(mp[nw].begin(), mp[nw].end(), mn);
                        auto x3 = lower_bound(mp[nw].begin(), mp[nw].end(), mx);
                        if (x1 != mp[nw].end())
                        {
                            int mid = *x1;
                            // cout << "x2 : " << mid << endl;

                            ans = min(ans, abs(x - mid) + abs(y - mid));
                        }
                        if (x3 != mp[nw].end())
                        {
                            int mid = *x3;
                            ans = min(ans, abs(x - mid) + abs(y - mid));
                        }
                        if (x1 != mp[nw].begin())
                        {
                            x1--;
                            int mid = *x1;
                            // cout << "x1 : " << mid << endl;
                            ans = min(ans, abs(x - mid) + abs(y - mid));
                        }
                    }
                }
            }
            if (ans == 1e8)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
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