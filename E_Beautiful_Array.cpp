#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int i, int mis, vector<int> &v, vector<vector<int>> &dp)
{
    int n = v.size();
    if (mis > 1)
        return 1e12;
    if (i + 1 >= n)
        return 0;
    if (dp[i][mis] != -1)
        return dp[i][mis];
    int left = fun(i + 2, mis, v, dp) + (v[i + 1] - v[i]);
    int right = fun(i + 1, mis + 1, v, dp);
    return dp[i][mis] = min(left, right);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<int, vector<int>> mp;
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x = v[i] % k;
        mp[x].push_back(v[i]);
    }
    int odd = 0;

    for (auto x : mp)
    {
        // cout << x.first << endl;
        auto Arr = x.second;
        sort(Arr.begin(), Arr.end());

        if (Arr.size() % 2 == 1)
        {
            odd++;
            if (n % 2 == 0 && odd >= 1)
            {
                cout << -1 << endl;
                return;
            }
            if (n % 2 == 1 && odd >= 2)
            {
                cout << -1 << endl;
                return;
            }
            int mx = 0;
            int sum1 = 0;
            vector<int> temp;
            vector<vector<int>> dp(Arr.size() + 1, vector<int>(2, -1));

            sum1 = fun(0, 0, Arr, dp);
            // cout << "sum1 : " << sum1 << endl;
            sum += sum1;
        }
        else
        {
            for (int i = 1; i < Arr.size(); i += 2)
            {
                sum += (Arr[i] - Arr[i - 1]);
            }
        }
        // cout << sum << endl;
    }
    cout << sum / k << endl;
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