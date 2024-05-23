#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        ans = max(ans, v[i]);
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i] - i].push_back(i);
    }
    for (auto x : mp)
    {
        int sum = 0;
        auto Arr = x.second;
        for (int i = 0; i < Arr.size(); i++)
        {
            sum += Arr[i];
        }
        sum += ((int)Arr.size() * (x.first));
        ans = max(ans, sum);
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