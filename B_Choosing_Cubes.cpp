#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ele = v[f - 1];
    sort(v.rbegin(), v.rend());
    int ele2 = k - 1 < 0 ? 1e8 : v[k - 1];
    int ele3 = k >= n ? 1e8 : v[k];
    if (k == n)
    {
        cout << "YES" << endl;
        return;
    }
    if (ele3 == ele && ele2 == ele)
    {
        cout << "MAYBE" << endl;
        return;
    }
    if (ele > ele3)
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