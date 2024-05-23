#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n = 1e6;
vector<int> dp(n + 1, 1e9);
void solve()
{
    int n1;
    cin >> n1;
    cout << dp[n1] << endl;
}
signed main()
{
    int t;
    vector<int> fac;
    int x = 1;
    int y = 1;
    while (x <= n)
    {
        x = x * y;
        y++;
        fac.push_back(x);
    }
    x = 1;
    while (pow(2, x) <= n)
    {
        if (binary_search(fac.begin(), fac.end(), pow(2, x)) == 0)
            fac.push_back(pow(2, x));
        x++;
    }
    sort(fac.begin(), fac.end());
    dp[0] = 0;
    dp[1] = 1;
    for (int j = 0; j <= n; j++)
    {
        for (int i = 0; i < fac.size(); i++)
        {

            if (j - fac[i] >= 0)
            {
                (dp[j] = min(dp[j], 1 + dp[j - fac[i]]));
            }
        }
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
}