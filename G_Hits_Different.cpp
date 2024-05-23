#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> dp(2*1e6 + 10, -1);
int sz = 1500;
vector<vector<int>> v(sz, vector<int>(sz, 0));

void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
signed main()
{
    int t;
    cin >> t;
    int x = 1;
    int incx = 2;
    for (int i = 0; i < sz; i++)
    {
        x += (i);
        int y = x;
        v[i][0] = y;
        y = (x + incx);
        int inc = incx;
        // cout << v[i][0] << " ";
        for (int j = 1; j < sz; j++)
        {
            v[i][j] = y;
            inc++;
            y += inc;
            // cout << v[i][j] << " ";
        }
        incx++;
        // cout << endl;
    }
    dp[1] = 1;
    for (int i = 1; i < sz; i++)
    {
        int curr = v[0][i];
        if(curr<1e6+10)
        dp[curr] = curr * curr + dp[v[0][i - 1]];
    }
    for (int i = 1; i < sz; i++)
    {
        int curr = v[i][0];
        if(curr<1e6+10)
        dp[curr] = curr * curr + dp[v[i - 1][0]];
    }
    for (int i = 1; i < sz; i++)
    {
        for (int j = 1; j < sz; j++)
        {
            
            int curr = v[i][j];
            if(curr<1e6+10)
            dp[curr] = curr * curr + dp[v[i - 1][j]] + dp[v[i][j - 1]] - dp[v[i - 1][j - 1]];
        }
    }
    while (t--)
    {
        solve();
    }
}