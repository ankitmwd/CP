#include <bits/stdc++.h>
using namespace std;
#define int long long int
int pow1(int n)
{
    return pow(2, n);
}
void solve()
{
    int n, x;
    cin >> n >> x;
    int pos = 1;
    int sz = 60;
    vector<int> v(sz, 0), v2(sz, 0);
    if (n == x)
    {
        cout << n << endl;
        return;
    }
    if (x > n)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < sz; i++)
    {
        int x1 = pow1(i);
        if ((x & x1))
        {
            v2[i] = 1;
            if ((n & x1) == 0)
            {
                pos = 0;
            }
        }
    }
    for (int i = 0; i < sz; i++)
    {
        int x1 = pow1(i);
        if ((n & x1) != 0)
        {
            v[i] = 1;
        }
    }
    if (!pos)
    {
        cout << "-1" << endl;
        return;
    }
    int last = 0;
    for (int i = 0; i < sz; i++)
    {
        if (v[i] == 1)
        {
            last = i;
        }
    }
    int sign = 1;
    for (int i = last - 1; i >= 0; i--)
    {
        if (v[i] == 1)
            sign = 0;
    }
    int sign2 = 0;
    for (int i = last; i >= 0; i--)
    {
        if (v[i] == 1 && v2[i] == 0)
        {
            sign2 = 1;
        }
        if (v[i] == 0)
        {
            break;
        }
    }
    int num = 0;
    if (x == 0 || sign || sign2)
    {
        num = x;
        num += (pow1(last + 1));
        // cout << num << endl;
    }
    else
    {
        int mn = -1;

        num = pow1(last);
        for (int i = last; i >= 1; i--)
        {

            if (v2[i - 1] == 1)
            {
                num += (pow1(i - 1));
            }
            else if (v[i - 1] == 1 && mn == -1)
            {
                mn = i;
            }
        }
        if (mn != -1)
            num += pow1(mn);
        // cout << num << endl;
    }
    int diff = num - x;
    // cout << "diff " << diff << endl;
    for (int i = 0; i < sz; i++)
    {
        if (v2[i] == 1)
        {
            if (diff >= (pow1(i)))
            {
                cout << "-1" << endl;
                return;
            }
        }
    }
    cout << num << endl;
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