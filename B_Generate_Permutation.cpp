#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int i = 0;
        int j = n - 1;
        vector<int> ans(n, 0);
        int mx = n;
        while (j >= i)
        {
            ans[i] = mx;
            mx--;
            i++;
            if (i > j)
                break;
            ans[j] = mx;
            mx--;
            j--;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
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