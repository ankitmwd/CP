#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int i, vector<pair<int, int>> &v, vector<vector<int>> &dp, int tot)
{
    int n = v.size();
    if (tot == 0)
        return 0;
    if (i >= n)
        return 1e15;
    int Pick = 1e15;
    if (dp[i][tot] != -1)
        return dp[i][tot];
    if (tot >= v[i].second)
        Pick = fun(i + 1, v, dp, tot - v[i].second) + v[i].first;
    int NotPick = fun(i + 1, v, dp, tot);
    return dp[i][tot] = min(Pick, NotPick);
}
void solve()
{
    int n, tot;
    cin >> n >> tot;
    int sum = 0;
    vector<pair<int, int>> v1;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v1.push_back({x, y});
        sum += y;
    }
    int mx_val = 1e5;
    vector<vector<int>> dp(n + 1, vector<int>(mx_val + 1, -1));
    for (int i = mx_val; i >= 0; i--)
    {
        if (fun(0, v1, dp, i) <= tot)
        {
            cout << i << endl;
            return;
        }
    }
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