#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int a, b;
    cin >> a >> b;
    int cnt = a;
    for (int i = 2; i <= b; i++)
    {
        cnt += (a + i) / (i * i);
        if ((a + i) / (i * i) == 0)
            break;
    }
    cout << cnt << endl;
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