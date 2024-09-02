#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    vector<int> fac;
    int n, k;
    cin >> n >> k;
    int x = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            fac.push_back(i);
            if (n % i != i)
            {
                fac.push_back(n / i);
            }
        }
    }
    vector<int> v;
    if (n != x)
    {
        v.push_back(n);
    }
    sort(fac.begin(), fac.end());
    for (int i = 0; i < fac.size(); i++)
    {
        while (n % fac[i] == 0)
        {
            v.push_back(fac[i]);
            n = n / fac[i];
        }
    }
    if (n == x)
    {
        v.push_back(n);
    }
    sort(v.rbegin(), v.rend());
    int ans = 1;
    int exp = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (10 % v[i] == 0)
        {
            if (exp * (10 / v[i]) <= k)
            {
                exp *= (10 / v[i]);
                ans *= 10;
            }
            else
            {
                ans *= v[i];
            }
        }
        else
        {
            ans *= v[i];
        }
    }
    // cout << ans << endl;

    while (1)
    {
        if (exp * 10 <= k)
        {
            ans *= 10;
            exp *= 10;
        }
        else
        {
            if (k / exp >= 1)
            {
                ans *= (k / exp);
            }
            break;
        }
    }
    cout << ans << endl;
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