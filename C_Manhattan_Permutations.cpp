#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int z = 1;
    for (int i = 0; i < n; i += 2)
    {
        sum += 2 * (n - z);
        z += 2;
    }
    // cout << sum << endl;
    if (k % 2 == 1 || k > sum)
    {
        cout << "No" << endl;
        return;
    }
    vector<int> ans(n + 1, 0);
    int n1 = n;
    for (int i = 1; i <= n; i++)
    {
        if (k >= 2 * (n1 - i) && ans[i] == 0 && n1 > i)
        {
            ans[n1] = i;
            ans[i] = n1;
            k -= 2 * (n1 - i);
            n1--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
            ans[i] = i;
    }
    cout << "Yes" << endl;
    int sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
        sum2 += abs(ans[i] - i);
    }
    cout << endl;

    // cout << sum2 << endl;
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