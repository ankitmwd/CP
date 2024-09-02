#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int ind, int tot, vector<int> &pri, vector<int> &pag, vector<vector<int>> &dp)
{
    int n = pri.size();
    if (ind >= n)
        return 0;
    if (dp[ind][tot] != -1)
        return dp[ind][tot];
    int left = fun(ind + 1, tot, pri, pag, dp);
    int right = 0;
    if (tot >= pri[ind])
        right = fun(ind + 1, tot - pri[ind], pri, pag, dp) + pag[ind];
    return dp[ind][tot] = max(left, right);
}
signed main()
{
    int n, x;
    cin >> n >> x;
    vector<int> pri(n), pag(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pri[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pag[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j >= pri[i])
            {
                dp[i + 1][j] = max(dp[i][j - pri[i]] + pag[i], dp[i][j]);
            }
        }
    }
    cout << dp[n][x] << endl;
    // cout << fun(0, x, pri, pag, dp);
}