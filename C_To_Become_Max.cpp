#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool fun(int val, vector<int> v, int k)
{
    int n = v.size();
    int k1 = val;
    int org = k;
    for (int i = 0; i < n - 1; i++)
    {
        val = k1;
        k = org;
        if (v[i] >= val)
            return true;
        k -= (val - v[i]);
        val--;
        // cout << v[i] << " " << val << endl;
        for (int j = i + 1; j < n - 1; j++)
        {
            if (v[j] >= val)
            {
                if (k >= 0)
                    return true;
                break;
            }
            else
            {
                k -= (val - v[j]);
            }
            if (k < 0)
                break;
            val--;
            // cout << v[j] << " " << val << endl;
        }
        if (val <= v[n - 1] && k >= 0)
            return true;
    }
    if (val > v[n - 1] || k < 0)
    {
        return false;
    }
    return true;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int l = 0;
    int h = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        h = max(h, v[i]);
    }
    ans = h;
    h = 1e17;
    // fun(7, v, k);
    // return;
    while (h >= l)
    {
        int mid = (l + h) / 2;
        if (fun(mid, v, k))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
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