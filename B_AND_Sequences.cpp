#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 1e9 + 7;
int sele(int x)
{
    int sum = 1;
    for (int i = x; i >= x - 1; i--)
    {
        sum = (sum * i) % M;
    }
    // cout << sum << endl;
    return sum;
}
int fac(int n)
{
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum = (sum * i) % M;
    }
    return sum;
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
    int x = v[0];
    for (int i = 0; i < n; i++)
    {
        x &= v[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
            cnt++;
    }
    if (cnt < 2)
    {
        cout << 0 << endl;
        return;
    }
    int ans = sele(cnt);
    // ans = (ans * 2LL) % M;
    ans = (ans * fac(n - 2)) % M;
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