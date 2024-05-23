#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int i, int sum, int tot, vector<pair<int, int>> v1, map<pair<int, int>, int>mp)
{
    int n = v1.size();
    if (i >= n)
        return 0;
    if (mp[{i, sum}] != 0)
        return mp[{i, sum}];
    int left = -1e16;
    if (sum >= v1[i].first)
    {
        left = fun(i + 1, sum - v1[i].first + tot, tot, v1, mp) + v1[i].second;
    }
    int right = fun(i + 1, sum + tot, tot, v1, mp);
    return mp[{i, sum}] = max(left, right);
}
void solve()
{
    int n, tot;
    cin >> n >> tot;
    vector<pair<int, int>> v1;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v1.push_back({x, y});
    }
    map<pair<int, int>, int> mp;
    cout << fun(0, 0, tot, v1, mp) << endl;
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