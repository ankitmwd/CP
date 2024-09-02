#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int left = x - 1 >= 0 ? v[x - 1] : 0;
        cout << v[y] - left << endl;
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