#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 10;
vector<int> dp(N, 0);
const int M = 1e9 + 7;
void slv(int ind, int k, vector<int> &v)
{
    dp[0] = 1LL;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {

            if (i - v[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - v[j]]) % M;
            }
        }
    }
    for (int i = 1; i < N; i++)
    {
        dp[i] = (dp[i] + dp[i - 1]) % M;
    }
}
void solve()
{
    int x, y;
    cin >> x >> y;
    // cout << dp[y] << " " << dp[x - 1] << endl;
    cout << (dp[y] - dp[x - 1] + M) % M << endl;
}
signed main()
{
    int t, k;
    cin >> t >> k;
    vector<int> v;
    v.push_back(1LL);
    v.push_back(k);
    slv(0, k, v);
    while (t--)
    {
        solve();
    }
}