#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int x, y, k;
    cin >> x >> k >> y;
    int yo = y;
    int xo = x;
    while ((x + y) >= k)
    {
        int z = x % k;
        int req = k - z;
        if (req > y)
            break;
        x += req;
        
    }
    cout << x + y << endl;
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