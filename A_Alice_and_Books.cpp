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
    int mx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        mx = max(mx, v[i]);
    }
    cout << mx + v[n - 1] << endl;
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