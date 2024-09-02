#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }
    int x = v[0] + 1;
    vector<int> ans(n, 0);
    ans[0] = x;
    for (int i = 0; i < n - 1; i++)
    {
        ans[i + 1] = ans[i] + v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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