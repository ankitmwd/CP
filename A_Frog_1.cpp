#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int i, vector<int> &v, vector<int> &dp)
{
    int n = v.size();
    if (i == n - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int left = fun(i + 1, v, dp) + abs(v[i] - v[i + 1]);
    int right = 1e8;
    if (i + 2 < n)
    {
        right = fun(i + 2, v, dp) + abs(v[i] - v[i + 2]);
    }
    return dp[i] = min(left, right);
}
signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(v[i] - v[i - 1]);
        int right = 1e8;
        if (i >= 2)
        {
            right = dp[i - 2] + abs(v[i] - v[i - 2]);
        }
        dp[i] = min(left, right);
    }
    cout << dp[n - 1];
    // cout << fun(0, v, dp);
}