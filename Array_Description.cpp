#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 1e9 + 7;
int fun(int i, int m, int prev, vector<int> &v, vector<vector<int>> &dp)
{
    int n = v.size();
    if (i >= n)
        return 1;
    if (prev > m)
        return 0;
    if (prev < 0)
        return 0;
    if (v[i] != 0 && abs(v[i] - prev) > 1)
        return 0;
    int sum = 0;
    if (dp[i][prev] != -1)
        return dp[i][prev];
    if (i == 0 && v[i] == 0)
    {
        for (int j = 1; j <= m; j++)
        {
            (sum += fun(i + 1, m, j, v, dp)) % M;
        }
    }
    else if (v[i] == 0)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (prev - j >= 1 && prev - j <= m)
                (sum += fun(i + 1, m, prev - j, v, dp)) % M;
        }
    }
    else
    {
        (sum += fun(i + 1, m, v[i], v, dp)) % M;
    }
    return dp[i][prev] = sum % M;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2 * m, -1));
    cout << fun(0, m, v[0], v, dp);
}