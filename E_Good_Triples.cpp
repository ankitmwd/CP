#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> dp(10, 0);
void fun(int ind, vector<int> &v, int n, vector<int> temp, set<vector<int>> &ans)
{
    if (n == 0 && temp.size() <= 3)
    {
        vector<int> temp2 = temp;
        while (temp2.size() < 3)
        {
            temp2.push_back(0);
        }
        sort(temp2.begin(), temp2.end());
        ans.insert(temp2);
        return;
    }
    if (temp.size() > 3 || ind >= 9 || n < 0)
        return;
    temp.push_back(v[ind]);
    fun(ind, v, n - v[ind], temp, ans);
    temp.pop_back();
    fun(ind + 1, v, n, temp, ans);
}
int cnt(set<vector<int>> ans)
{
    int tot = 0;
    for (auto x : ans)
    {
        vector<int> temp = x;
        map<int, int> mp;
        for (int i = 0; i < 3; i++)
        {
            // cout << temp[i] << " ";
            mp[temp[i]]++;
        }
        // cout << endl;
        int sum = 6;
        for (auto y : mp)
        {
            if (y.second == 3)
            {
                sum /= 6;
            }
            else if (y.second == 2)
            {
                sum /= 2;
            }
        }
        // cout << sum << endl;
        tot += sum;
    }
    return tot;
}
void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    while (n)
    {
        int x = n % 10;
        n = n / 10;
        ans *= dp[x];
    }
    cout << ans << endl;
}
signed main()
{
    int t;
    cin >> t;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= 9; i++)
    {
        vector<int> temp;
        set<vector<int>> ans;
        fun(0, v, i, temp, ans);
        dp[i] = cnt(ans);
    }
    while (t--)
    {
        solve();
    }
}