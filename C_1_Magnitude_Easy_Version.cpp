#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 998244353;
int fun(int ind, vector<int> &v, vector<int> &dp)
{
    int n = v.size();
    if (ind < 0)
        return 0;
    int left = fun(ind - 1, v, dp) + v[ind];
    int right = abs(fun(ind - 1, v, dp)) + v[ind];
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v1(n);
    int tot = 0;
    int tot1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        tot1 = max(abs(tot1), abs(tot)) + v[i];
        if (tot1 >= 0)
        {
            tot1 = tot1 % M;
        }
        else
        {
            tot1 = M - abs(tot1) % M;
        }

        tot += v[i];
        if (tot >= 0)
        {
            tot1 = tot % M;
        }
        else
        {
            tot1 = M - abs(tot1) % M;
        }
    }
    cout << max(abs(tot), abs(tot1)) << endl;
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