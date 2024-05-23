#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    vector<int> sum1 = v2;
    vector<int> extra(n, 0);
    vector<int> ans(n, 0);

    for (int i = 1; i < n; i++)
    {
        sum1[i] += sum1[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        int last = 0;
        if (i > 0)
        {
            last = sum1[i - 1];
        }
        int ind = upper_bound(sum1.begin(), sum1.end(), v1[i] + last) - sum1.begin();
        // cout << ind << endl;
        if (ind >= n)
        {
            ans[i]++;
        }
        else
        {
            ans[i]++;
            ans[ind]--;
            extra[ind] += v1[i] + last - (ind > 0 ? sum1[ind - 1] : 0);
            // cout << extra[ind] << endl;
        }
    }
    for (int i = 1; i < n; i++)
    {
        ans[i] += ans[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = ans[i] * v2[i] + extra[i];
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