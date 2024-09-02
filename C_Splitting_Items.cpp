#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> mp;
    int mn = 1e10;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    int ans = 0;
    sort(v.begin(), v.end());
    while (v.size())
    {
        if (v.size() == 1)
        {
            ans += v[0];
            break;
        }
        int s1 = v[v.size() - 1];
        v.pop_back();
        int s2 = v[v.size() - 1];
        v.pop_back();
        if (s1 - s2 <= k)
        {
            k -= (s1 - s2);
        }
        else
        {
            s2 += k;
            k = 0;
            ans += (s1 - s2);
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