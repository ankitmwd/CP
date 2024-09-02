#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 998244353;
int pw(int n, int a)
{
    int z = 1;
    while (a)
    {
        if (a % 2 == 1)
        {
            z = ((z % M) * (n % M)) % M;
        }
        a = a / 2;
        n = ((n % M) * (n % M)) % M;
    }
    return z;
}
int div(int n)
{
    return pw(n, M - 2) % M;
}
int nCr(int n, int r)
{
    int x = 1;
    for (int i = n; i > n - r; i--)
    {
        x = (x * i) % M;
    }
    // cout << x << endl;
    for (int i = 2; i <= r; i++)
    {
        // cout << div(i) << endl;
        x = (x * div(i)) % M;
    }
    return x;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans;
    for (int i = 2; i < n; i += 3)
    {
        int mn = min({v[i], v[i - 1], v[i - 2]});
        int cnt = 0;
        if (v[i] == mn)
        {
            cnt++;
        }
        if (v[i - 1] == mn)
        {
            cnt++;
        }
        if (v[i - 2] == mn)
        {
            cnt++;
        }
        ans.push_back(cnt);
    }
    int z = n;
    int res = nCr(z / 3, z / 6);
    // cout << res << endl;
    // return;
    for (int i = 0; i < ans.size(); i++)
    {
        res = (res * ans[i]) % M;
    }
    cout << res % M << endl;
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