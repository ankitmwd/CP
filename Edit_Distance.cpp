#include <bits/stdc++.h>
using namespace std;
int fun(int i, int j, int Add, string &s1, string &s2, vector<vector<vector<int>>> &dp)
{
    int n = s1.size();
    int m = s2.size();
    // m is greater then n
    if (j >= m && n + Add == m)
        return 0;
    if (j >= m)
        return 1e8;
    int rem = m - j;
    if (i >= n && i + Add + rem == m)
        return rem;
    if (i >= n)
        return 1e8;
    if (dp[i][j][Add] != -1)
        return dp[i][j][Add];
    int extra = 1e8;
    if (s1[i] == s2[j])
    {
        extra = fun(i + 1, j + 1, Add, s1, s2, dp);
    }
    int left = fun(i + 1, j + 1, Add, s1, s2, dp) + 1;
    int right = 1e8;
    if (n + Add + 1 <= m)
        right = fun(i, j + 1, Add + 1, s1, s2, dp) + 1;
    return dp[i][j][Add] = min({left, right, extra});
}
signed main()
{
    string s1, s2;

    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    if (n > m)
    {
        swap(s1, s2);
    }
    vector<vector<vector<int>>> dp(min(n + 1, m + 1), vector<vector<int>>(max(m + 1, n + 1), vector<int>(abs(m - n) + 2, -1)));
    cout << fun(0, 0, 0, s1, s2, dp);
}