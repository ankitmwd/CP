#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int sum = 0;
    map<int, int> mp;
    // mp[0] = 1;
    int cnt = 0;
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        mx = max(mx, v[i]);
        if (sum - mx == mx)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
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