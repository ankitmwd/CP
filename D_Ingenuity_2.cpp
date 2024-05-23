#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    map<char, int> mp;
    int cnt1 = 0;
    int cnt2 = 0;
    string str;
    cin >> str;
    if (n % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'N')
            cnt1++;
        if (str[i] == 'S')
            cnt1--;
        if (str[i] == 'W')
            cnt2++;
        if (str[i] == 'E')
            cnt2--;
    }
    cnt1 = abs(cnt1);
    cnt2 = abs(cnt2);
    if (cnt1 % 2 == 1 || cnt2 % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (cnt1 == 0 && cnt2 == 0 && n <= 2)
    {
        cout << "NO" << endl;
        return;
    }
    vector<char> ans(n, 'A');
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'N')
        {
            if (sign)
            {
                ans[i] = 'R';
                sign = !sign;
            }
            else
            {
                ans[i] = 'H';
                sign = !sign;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'S')
        {
            if (sign == 0)
            {
                ans[i] = 'R';
                sign = !sign;
            }
            else
            {
                ans[i] = 'H';
                sign = !sign;
            }
        }
    }
    sign = 1;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'E')
        {
            if (sign)
            {
                ans[i] = 'H';
                sign = !sign;
            }
            else
            {
                ans[i] = 'R';
                sign = !sign;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'W')
        {
            if (sign == 0)
            {
                ans[i] = 'H';
                sign = !sign;
            }
            else
            {
                ans[i] = 'R';
                sign = !sign;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
    }
    cout << endl;
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