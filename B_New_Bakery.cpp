#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a >= b)
    {
        cout << n * (a) << endl;
    }
    else
    {
        int sum = (b * (b + 1)) / 2;
        int sum1 = (a * (a + 1)) / 2;
        int z = b - a;
        if (n >= z)
        {
            int cost = sum - sum1;
            cout << sum - sum1 + ((n - z) * a)<<endl;
        }
        else
        {
            int x1 = b - n;
            int sum3 = (x1 * (x1 + 1)) / 2;
            cout << sum - sum3 << endl;
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