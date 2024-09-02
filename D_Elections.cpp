#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, und;
    cin >> n >> und;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    v[0] += und;
    int ind = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > mx)
        {
            mx = v[i];
            ind = i;
        }
    }
    vector<int> ans(n, 0);
    int x = 0;
    for (int i = ind; i < n; i++)
    {
        ans[i] = x;
        x = i + 1;
    }
    int sum = v[0];
    int sum1 = 0;
    for (int i = 0; i < ind; i++)
    {
        sum1 += v[i];
        if (sum1 >= mx)
        {
            ans[i] = i;
        }
        else
        {

            ans[i] = i + 1;
        }
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