#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int plus = 0;
    int minus = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '+')
        {
            plus++;
        }
    }
    minus = n - plus;
    int q;
    cin >> q;
    if (plus < minus)
    {
        swap(plus, minus);
    }
    int temp = plus;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int cm = (a * b) / (__gcd(a, b));
        plus = temp;
        minus = n - plus;
        while (plus >= 0 && minus >= 0)
        {
            if (plus == minus && plus >= 0)
            {
                cout << "YES" << endl;
                break;
            }
            int mx = max(a, b);
            int mn = min(a, b);
            plus -= cm / mn;
            minus -= cm / mx;
            if (plus == minus && plus >= 0)
            {
                cout << "YES" << endl;
                break;
            }
            if (plus < 0 || minus < 0)
            {
                cout << "NO" << endl;
                break;
            }
        }
    }
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}