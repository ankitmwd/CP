#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int h, int w, int n, int req_w)
{
    if (h == n && w == req_w)
        return 1;
    if (h > n || w > 2)
        return 0;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= req_w; j++)
        {
            if (!(i == 0 && j == 0))
                sum += fun(h + i, w + j, n, req_w);
        }
    }
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    cout << fun(0, 0, n, 2) << endl;
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