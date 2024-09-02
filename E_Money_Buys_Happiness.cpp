#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int i, int tot_money, int Happiness, int inc, vector<pair<int, int>> &v, vector<vector<int>> &curr, vector<vector<int>> &dp)
{
    int n = v.size();
    if (i == n - 1)
        return tot_money >= v[i].first ? v[i].second : 0;
    if (dp[i][Happiness] != -1 && curr[i][Happiness] >= tot_money)
    {
        return dp[i][Happiness];
    }
    int Take = 0;
    int NotTake = fun(i + 1, tot_money + inc, Happiness, inc, v, curr, dp);
    if (tot_money >= v[i].first)
        Take = fun(i + 1, tot_money + inc - v[i].first, Happiness + v[i].second, inc, v, curr, dp) + v[i].second;
    curr[i][Happiness] = tot_money;
    return dp[i][Happiness] = max(NotTake, Take);
}
void solve()
{
    int n, tot;
    cin >> n >> tot;
    vector<pair<int, int>> v1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v1.push_back({x, y});
        sum += y;
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    vector<vector<int>> curr_money(n + 1, vector<int>(sum + 1, 0));
    cout << fun(0, 0, 0, tot, v1, curr_money, dp) << endl;
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