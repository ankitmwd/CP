#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 0; i <= 32; i++)
    {
        int x = pow(2, i);
        if ((n1 & x) != (n2 & x))
        {
            cout << x << endl;
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