#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 1e9 + 7;
int pw(int a, int b)
{
    int x = 1;
    a = a % M;
    while (b)
    {
        if ((b & 1) == 1)
        {
            x = (x * a) % M;
        }
        a = (a * a) % M;
        b = b >> 1;
    }
    return x % M;
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
    for (int i = n - 1; i >= 1; i--)
    {
        sum[i - 1] = (sum[i - 1] + sum[i]) % M;
    }
    int total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        total = total + (v[i] * (sum[i + 1])) % M;
    }
    n = (n * (n - 1)) / 2;
    // n = n % M;
    if (total % n == 0)
    {
        cout << total / n << endl;
    }
    else
    {
        int x = pw(n, M - 2);
        cout << ((total * x) % M) << endl;
    }
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