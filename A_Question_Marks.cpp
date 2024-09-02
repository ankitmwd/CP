#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int A = 0, B = 0, C = 0,
        D = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'A')
            A++;
        if (str[i] == 'B')
            B++;
        if (str[i] == 'C')
            C++;
        if (str[i] == 'D')
            D++;
    }
    if (A >= n)
    {
        A = n;
    }
    if (B >= n)
    {
        B = n;
    }
    if (C >= n)
    {
        C = n;
    }
    if (D >= n)
    {
        D = n;
    }
    cout << A + B + C + D << endl;
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