#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool fun(int ind, string &s, int k, int cnt1, int cnt0)
{
    if (cnt0 != cnt1 && ind >= (k))
        return false;
    int n = s.size();
    if (ind >= n)
        return true;
    bool sum = false;
    if (ind - k >= 0)
    {
        if (s[ind - k] == '1')
            cnt1--;
        else
            cnt0--;
    }
    if (s[ind] == '1')
    {
        sum |= fun(ind + 1, s, k, cnt1 + 1, cnt0);
    }
    else if (s[ind] == '0')
    {
        sum |= fun(ind + 1, s, k, cnt1, cnt0 + 1);
    }
    else
    {
        s[ind] = '0';
        sum |= fun(ind + 1, s, k, cnt1, cnt0 + 1);
        s[ind] = '?';
        s[ind] = '1';
        sum |= fun(ind + 1, s, k, cnt1 + 1, cnt0);
        s[ind] = '?';
    }
    return sum;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool x = fun(0, s, k, 0, 0);
    if (x)
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