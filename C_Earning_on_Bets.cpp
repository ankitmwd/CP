#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sum=1e9;
    vector<int> ans(n, 0);
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i] = sum / v[i] + 1;
        sum2 += ans[i];
        // cout<<ans[i]<<endl;
    }
    if (sum2 > sum)
    {
        cout << "-1" << endl;
        return;
    }
    int extra = sum - sum2;
    ans[0] += extra;
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