#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    string str;
    cin >> str;
    int n = str.size() - 2;
    vector<int> v(n, 0);
    for (int i = 1; i < str.size() - 1; i++)
    {
        if (str[i] == '(')
        {
            v[i - 1] = 1;
        }
        else
        {
            v[i - 1] = -1;
        }
    }
    map<int, int> mp;
    if (v.size())
        mp[v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
        mp[v[i]]++;
    }
    int cnt = (mp[0] * (mp[0] + 1)) / 2;
    int cnt1 = 0;
    for (auto x : mp)
    {
        if (x.first != 0)
        {
            cnt1 += (mp[x.first] * mp[-x.first]);
        }
    }
    cout << cnt + cnt1 / 2 << endl;
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