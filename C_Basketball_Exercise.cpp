#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> dp(1e5 + 10, vector<int>(3, 0));
int fun(int ind, int prev, vector<int> v1, vector<int> v2)
{
    int n = v1.size();
    if (ind >= n)
        return 0;
    // if (dp[ind][prev] != -1)
    // return dp[ind][prev];
    int l1 = -1e18, l2 = -1e18, l3 = -1e18;
    if (prev != 0)
    {
        l1 = fun(ind + 1, 0, v1, v2) + v1[ind];
    }
    if (prev != 1)
    {
        l2 = fun(ind + 1, 1, v1, v2) + v2[ind];
    }
    l3 = fun(ind + 1, 2, v1, v2);
    return max({l1, l2, l3});
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int l1 = -1e18, l2 = -1e18, l3 = -1e18;
            if (j == 0)
                l1 = max(dp[i - 1][j + 1], dp[i - 1][j + 2]) + v1[i - 1];
            if (j == 1)
                l2 = max(dp[i - 1][j - 1], dp[i - 1][j + 1]) + v2[i - 1];
            l3 = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][j] = max({l1, l2, l3});
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}
signed main()
{

    solve();
}