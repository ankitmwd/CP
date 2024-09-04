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
    vector<int> sum = v;
    for (int i = 1; i < n; i++)
    {
        sum[i] += sum[i - 1];
    }
    while (q--)
    {
        // cout << "one" << endl;
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if ((l / n) == (r / n))
        {
            // cout << "one" << endl;
            int ele = r - l;
            int ph = floor((l * 1.0) / n);
            ph = ph % n;
            int ans = 0;
            int start = l % n;
            int z = (ph + start) % n;
            // cout << "phase : " << ph << endl;
            if (ele + z < n)
            {
                ans += (sum[ele + z] - (z - 1 >= 0 ? sum[z - 1] : 0));
            }
            else
            {
                ans += (sum[n - 1] - (z - 1 >= 0 ? sum[z - 1] : 0));
                int extra = ele + z - n;
                ans += sum[extra];
            }
            cout << ans << endl;
        }
        else
        {
            int ph = floor((l * 1.0) / n);
            ph = ph % n;
            int ans = 0;
            int ele = (n - 1) - l % n;
            int start = l % n;
            // cout << ph << " " << ph + ele << endl;
            int z = (start + ph) % n;
            if (ele + z < n)
            {
                ans += (sum[ele + z] - (z - 1 >= 0 ? sum[z - 1] : 0));
            }
            else
            {
                ans += (sum[n - 1] - (z - 1 >= 0 ? sum[z - 1] : 0));
                int extra = ele + z - n;
                ans += sum[extra];
            }
            int ph1 = floor((r * 1.0) / n);
            ph1 = ph1 % n;
            int ans1 = 0;
            int ele1 = r % n;
            // cout << "Ans " << ans << endl;
            // cout << ph1 << " " << ph1 + ele1 << endl;
            if (ele1 + ph1 < n)
            {
                ans1 += (sum[ele1 + ph1] - (ph1 - 1 >= 0 ? sum[ph1 - 1] : 0));
            }
            else
            {
                ans1 += (sum[n - 1] - (ph1 - 1 >= 0 ? sum[ph1 - 1] : 0));
                int extra = ele1 + ph1 - n;
                ans1 += sum[extra];
            }
            int tot = 0;
            int x = (l / n);
            int y = (r / n);
            x++;
            // y--;
            if (y > x)
            {
                tot += (y - x) * sum[n - 1];
            }
            cout << ans + ans1 + tot << endl;
        }
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