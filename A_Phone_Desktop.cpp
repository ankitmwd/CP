#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int a, b;
    cin >> a >> b;
    int sum = b / 2 + b % 2;
    int ans = sum;
    // cout<<ans<<endl;
    if (b % 2 == 0)
    {
        int hav = (7 * (b / 2));
        // cout << hav << endl;
        if (a > hav)
        {
            a -= hav;
            ans += (a / 15);
            if (a % 15 != 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    else
    {
        int hav = (7 * (b / 2)) + 11;
        if (a > hav)
        {
            a -= hav;
            ans += (a / 15);
            if (a % 15 != 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
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