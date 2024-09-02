#include <bits/stdc++.h>
using namespace std;
#define int long long int
int M = 1e9 + 9;
int pw2(int n)
{
    int mul = 2LL;
    int ans = 1LL;
    while (n)
    {
        if ((n % 2) == 1)
        {
            ans = ((ans) % M * (mul) % M) % M;
        }
        n = n >> 1LL;
        mul = ((mul) % M * (mul) % M) % M;
    }
    // cout << ans << endl;
    return ans % M;
}
signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    k = k % M;
    int scr = 0;
    int tot = n / k;
    int rem = n % k;
    int fls = n - m;
    int pw = 0;
    if (tot > fls)
    {
        pw = tot - fls;
        pw = pw % M;
        int x = (((pw2(pw + 1) - 2 + M) % M) * k) % M;
        int rem_scr = (rem + ((fls) * (k - 1)) % M) % M;
        cout << (x + rem_scr) % M << endl;
    }
    else
    {

        cout << n - fls << endl;
    }
}