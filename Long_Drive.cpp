#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int x, y;
    cin >> x >> y;
    for (int i = 0; i <=1e4; i++)
    {
        int fac = (x * 10 + 100 * i) / (10 + i);
        if (fac >= y)
        {
            cout << i << endl;
            return;
        }
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