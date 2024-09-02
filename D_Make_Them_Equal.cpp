#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e3 + 10;
vector<int> Arr(N, N);
int mx = 0;
void prim()
{
    Arr[1] = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int x = i + i / j;
            if (x < N)
            {
                Arr[x] = min(Arr[x], Arr[i] + 1);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        mx = max(Arr[i], mx);
    }
    cout << mx << endl;
}
int fun(int i, vector<int> &step, vector<int> &cst, int k, vector<vector<int>> &dp)
{
    int n = cst.size();
    if (i >= n)
        return 0;
    int take = 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    if (k >= step[i])
    {
        take = fun(i + 1, step, cst, k - step[i], dp) + cst[i];
    }
    int Nottake = fun(i + 1, step, cst, k, dp);
    return dp[i][k] = max(take, Nottake);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> step(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> cst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cst[i];
    }
    for (int i = 0; i < n; i++)
    {
        step[i] = Arr[v[i]];
    }

    int M = 2e4;
    vector<vector<int>> dp(n + 1, vector<int>(M, -1));
    cout << fun(0, step, cst, min(k, M), dp) << endl;
}
signed main()
{
    int t;
    cin >> t;
    prim();
    while (t--)
    {
        solve();
    }
}