#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 1e9 + 7;
int pw1(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            x = (x * a) % M;
        }
        a = (a * a) % M;
        b = b / 2;
    }
    return x % M - 1;
}
void solve()
{
    int l, h, k;
    cin >> l >> h >> k;
    int cnt = (9 / k);
    int ans = 0;
    ans = (pw1(cnt + 1, h)) % M;
    int ans1 = (pw1(cnt + 1, l)) % M;

    cout << (ans - ans1 + M) % M << endl;
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