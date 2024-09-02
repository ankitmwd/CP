#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    int n = s1.size();
    int m = s2.size();
    if (i >= n)
        return 0;
    if (j >= m)
        return 0;
    int mid = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int cnt = 0;
    if (s1[i] == s2[j])
    {
        mid = fun(i + 1, j + 1, s1, s2, dp) + 1;
    }
    int left = fun(i + 1, j, s1, s2, dp);
    int right = fun(i, j + 1, s1, s2, dp);
    return dp[i][j] = max({left, mid, right});
}
int fun1(int j, string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    int i = 0;
    int cnt = 0;
    int mx = 0;
    int org = j;
    int lsti = 0;
    while (i < n && j < m)
    {
        if (s1[i] == s2[j])
        {
            cnt++;
            i++;
            j++;
            mx = max(mx, cnt);
        }
        else
        {
            i++;
            // org = j;
            // cnt = 0;
        }
    }
    return mx;
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int mx = 0;
    for (int j = 0; j < m; j++)
    {
        mx = max(mx, fun1(j, s1, s2));
    }
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // int x = fun(0, 0, s1, s2, dp);
    // cout << mx << endl;
    cout << (n + (m - mx)) << endl;
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