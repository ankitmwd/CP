#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int i, vector<int> &v, int k, vector<int> &dp)
{
    int n = v.size();
    if (i == n - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int mn = 1e18;

    for (int j = i + 1; j <= min(n - 1, i + k); j++)
    {
        mn = min(mn, fun(j, v, k, dp) + abs(v[i] - v[j]));
    }
    return dp[i] = mn;
}
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j < 0)
                break;
            dp[i] = min(dp[i - j] + abs(v[i] - v[i - j]), dp[i]);
        }
    }
    cout << dp[n - 1];
    // cout << fun(0, v, k, dp);
}