#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 998244353;
int N = 2 * 1e5 + 2;
vector<int> pw1(N, 1);
int pw(int n)
{
    return pw1[n];
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> sum = v;
    for (int i = 1; i < n; i++)
    {
        sum[i] += sum[i - 1];
    }
    int mn = *min_element(sum.begin(), sum.end());
    int ans = 0;
    if (mn >= 0)
    {
        ans = pw(n);
    }
    else
    {
        int pos = 0;
        int sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += v[i];
            if (sum[i] == mn)
            {
                ans = (ans + pw(n - i - 1 + pos)) % M;
            }
            if (sum1 >= 0)
                pos++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    int t;
    int x = 1;
    for (int i = 1; i < N; i++)
    {
        pw1[i] = (x * 2LL) % M;
        x = (x * 2) % M;
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
}