#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    int n = v.size();
    if (i == n)
        return 0;
    if (dp[i][j]<1e16)
        return dp[i][j];
    return dp[i][j] = min(fun(i + 1, j, v, dp) + v[i][j], fun(i + 1, j + 1, v, dp) + v[i][j]);
}
signed main()
{
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e18));
    cout << fun(0, 0, v, dp);
}

