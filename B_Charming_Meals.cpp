#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool bin(vector<int> &v1, vector<int> &v2, int val)
{
    int n = v1.size();
    vector<int> vis(n, 0);
    int cnt = 0;
    for (auto x : v1)
    {
        int y = lower_bound(v2.begin(), v2.end(), x + val) - v2.begin();
        // cout << y << endl;
        if (y < v2.size())
        {
            v2.erase(v2.begin() + y);
        }
        else
            break;
        cnt++;
    }
    for (auto x : v2)
    {
        int y = lower_bound(v1.begin() + cnt, v1.end(), x + val) - v1.begin();
        if (y < v1.size())
        {
            v1.erase(v1.begin() + y);
        }
        else
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    int l = 0;
    int h = 1e12;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans = l;
    while (h >= l)
    {
        int mid = (l + h) / 2;
        if (bin(v1, v2, mid))
        {
            l = mid + 1;
            ans = mid;
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