#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 2; i <= n; i += 2)
    {
        sum += i;
    }
    if (n >= sum)
    {
        cout << n << endl;
    }
    else
    {
        cout << 2 << endl;
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