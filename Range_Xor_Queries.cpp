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
        v[i] ^= v[i - 1];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int left = l - 1 >= 0 ? v[l - 1] : 0;
        cout << (v[r] ^ left) << endl;
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