#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    string str;
    cin >> str;
    int l = 0;
    int h = n - 1;
    vector<int> sum = v;
    for (int i = 1; i < n; i++)
    {
        sum[i] += sum[i - 1];
    }
    int ans = 0;
    while (h > l)
    {
        if (str[l] == 'L' && str[h] == 'R')
        {
            int left = l > 0 ? sum[l - 1] : 0;
            ans += (sum[h] - left);
            l++;
            h--;
        }
        if (str[l] == 'R')
        {
            l++;
        }
        if (str[h] == 'L')
        {
            h--;
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