#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int commonpos = 0;
    int commonneg = 0;
    int mx1 = 0;
    int mx2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] == 1)
                commonpos++;
            if (a[i] == -1)
                commonneg++;
        }
        else if (a[i] == 1)
        {
            mx1++;
        }
        else if (b[i] == 1)
            mx2++;
    }

    while (commonpos > 0)
    {
        if (mx1 > mx2)
        {
            mx2++;
        }
        else
            mx1++;
        commonpos--;
    }

    while (commonneg > 0)
    {
        if (mx1 > mx2)
        {
            mx1--;
        }
        else
            mx2--;
        commonneg--;
    }
    cout << min(mx1, mx2) << endl;
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