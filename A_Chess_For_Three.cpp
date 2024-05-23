#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    int sum = x + y + z;
    if (sum % 2 == 1)
    {
        cout << "-1" << endl;
        return;
    }
    if (x + y >= z)
    {
        cout << (sum) / 2 << endl;
    }
    else
    {
        cout << (x + y) << endl;
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