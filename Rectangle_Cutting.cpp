#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    if (a < 0 || b < 0)
        return 1e8;
    // int mn = min(a, b);
    int mx = 1e8;
    for (int i = 1; i <= a; i++)
    {
        mx = min(fun(a - i, b) + 1, mx);
    }
    for (int i = 1; i <= b; i++)
    {
        mx = min(fun(a, b - i) + 1, mx);
    }
    return mx;
}
signed main()
{
    int a, b;
    cin >> a >> b;
    cout << fun(a, b);
}