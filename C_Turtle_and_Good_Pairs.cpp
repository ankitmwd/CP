#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    vector<pair<int, char>> v;
    for (auto x : mp)
    {
        v.push_back({x.second, x.first});
    }
    sort(v.begin(), v.end());
    while (v.size())
    {
        int sz = v.size();
        int cnt1 = v[sz - 1].first;
        char ch1 = v[sz - 1].second;
        while (cnt1 > 0)
        {
            ans += ch1;
            cnt1--;
        }
        v.pop_back();
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