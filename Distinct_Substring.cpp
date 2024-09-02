#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << "YES" << endl;
        return;
    }
    int sum = (k - 1) + (((k + 1) * k) / 2);
    if (n >= sum)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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