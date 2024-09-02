#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool fun(vector<int> &v, vector<int> &c, int day, int h)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= h)
            return true;
        if ((day - 1) / c[i] >= h)
            return true;
        h -= (1 + ((day - 1) / c[i])) * v[i];
    }
    if (h <= 0)
        return true;
    return false;
}
void solve()
{
    int n, val;
    cin >> val >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int l = 1;
    int h = 1e13;
    int ans = h;
    while (h >= l)
    {
        int mid = (h - l) / 2 + l;
        if (fun(v, c, mid, val))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
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