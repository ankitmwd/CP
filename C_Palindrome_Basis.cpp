#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> pl;
vector<int> dp(4 * 1e4 + 1, 0);
int M = 1e9 + 7;
bool is_plan(int n)
{
    string str = to_string(n);
    int sz = str.size();
    for (int i = 0; i < (sz + 1) / 2; i++)
    {
        if (str[i] != str[sz - 1 - i])
            return false;
    }
    return true;
}
void plan()
{
    int n = 4 * 1e4;
    for (int i = 1; i <= n; i++)
    {
        if (is_plan(i))
        {
            pl.push_back(i);
        }
    }
}
int fun(int ind, int n, vector<int> &pl, vector<int> &dp)
{
    dp[0] = 1;
    for (int j = 0; j < pl.size(); j++)
    {
        for (int i = 1; i <= n; i++)
        {

            if (i - pl[j] >= 0)
            {
                (dp[i] += dp[i - pl[j]]) %= M;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
signed main()
{
    int t;
    plan();
    int n = 4 * 1e4;
    fun(0, n, pl, dp);
    cin >> t;
    while (t--)
    {
        solve();
    }
}