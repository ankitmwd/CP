#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        cin >> b[i];
    }
    int num = b[n];
    int last = 1e17;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += abs(a[i] - b[i]);
        int mx = max(a[i], b[i]);
        int mn = min(a[i], b[i]);
        if (mx >= num && mn <= num)
        {
            last = 0;
        }
        last = min({last, abs(a[i] - num), abs(b[i] - num)});
    }
    cout << cnt + last + 1 << endl;
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