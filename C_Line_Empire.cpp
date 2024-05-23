#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, pos, con;
    cin >> n >> pos >> con;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<int> shift(n + 1, 0), Winning(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        Winning[i] = v[i];
        int sht = (v[i] - v[i - 1]) * pos + (v[i] - v[i - 1]) * con;
        shift[i] = sht;
    }
    for (int i = 1; i <= n; i++)
    {
        shift[i] += shift[i - 1];
        Winning[i] += Winning[i - 1];
    }
    int ans = 1e17;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, shift[i] + ((Winning[n] - Winning[i]) - (n - i) * v[i]) * con);
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