#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int ind, vector<vector<int>> &v, int prev, vector<vector<int>> &dp)
{
    int n = v.size();
    if (ind >= n)
        return 0;
    int mx = 0;
    if (dp[ind][prev] != -1)
        return dp[ind][prev];
    for (int i = 0; i < 3; i++)
    {
        if (i != prev)
            mx = max(mx, fun(ind + 1, v, i, dp) + v[ind][i]);
    }
    return dp[ind][prev] = mx;
}
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    cout << fun(0, v, 3, dp);
}