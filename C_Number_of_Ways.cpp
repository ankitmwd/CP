#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }
    sum = sum / 3;
    map<int, int> mp;
    int sum1 = 0;
    int sum2 = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += v[i];
        sum2 += v[i];
        if (sum2 == sum)
        {
            cnt++;
            sum2 = 0;
        }
        if (sum1 == sum || sum1 % sum == 0)
        {
            mp[sum1]++;
        }
    }

    if (cnt <= 2 || sum2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    sum1 = 0;
    cnt = 0;
    map<int, int> mp2;
    for (int i = 0; i < n; i++)
    {
        sum1 += v[i];
        if (sum1==sum || sum1 % sum == 0)
        {
            if (sum1 == sum)
                cnt += (mp[2 * sum]);
            if (sum1 == 2 * sum)
                mp[2 * sum]--;
        }
    }
    cout << cnt << endl;
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