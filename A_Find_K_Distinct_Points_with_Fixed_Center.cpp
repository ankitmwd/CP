#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int s1 = 0, s2 = 0;
    int sum = 0;
    int x = 1;
    if (k % 2 == 0)
    {
        while (k)
        {
            s1 = a + x;
            s2 = b + x;
            cout << s1 << " " << s2 << endl;
            s1 = a - x;
            s2 = b - x;
            cout << s1 << " " << s2 << endl;
            x++;
            k -= 2;
        }
    }
    else
    {
        cout << a << " " << b << endl;
        k--;
        while (k)
        {
            s1 = a + x;
            s2 = b + x;
            cout << s1 << " " << s2 << endl;
            s1 = a - x;
            s2 = b - x;
            cout << s1 << " " << s2 << endl;
            x++;
            k -= 2;
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