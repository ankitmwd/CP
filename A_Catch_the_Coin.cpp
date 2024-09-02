#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int x, y;
    cin >> x >> y;
    // x = y - x;
    if (y < 0)
    {
        if (abs(y) >= 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    else
    {
        cout << "YES" << endl;
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