#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]].push_back(i + 1);
    }
    map<int, int> ans;
    for (auto x : mp)
    {
        auto Arr = x.second;
        Arr.push_back(n + 1);
        int mn = Arr[0] - 0;
        for (int i = 1; i < Arr.size(); i++)
        {
            mn = max(mn, Arr[i] - Arr[i - 1]);
        }
        if (ans[mn] == 0)
        {
            ans[mn] = x.first;
        }
        else
        {
            ans[mn] = min(ans[mn], x.first);
        }
    }
    int prev = -1;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != 0)
        {
            if (prev != -1)
            {
                prev = min(prev, ans[i]);
            }
            else
            {
                prev = ans[i];
            }
        }
        cout << prev << " ";
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