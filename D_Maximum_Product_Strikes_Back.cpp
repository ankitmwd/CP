#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int i = 0;
    int j = 0;
    int mx = 0;
    pair<int, int> p = {-1, -1};
    while (i < n)
    {
        while (i < n && v[i] == 0)
        {
            i++;
        }
        // cout << i << endl;

        if (i >= n)
            break;
        j = i;
        while (j < n && v[j] != 0)
        {
            j++;
        }
        // cout << j << endl;
        // break;
        int neg = 0;
        int two = 0;
        for (int k = i; k < j; k++)
        {
            if (v[k] < 0)
                neg++;
            if (abs(v[k]) == 2)
                two++;
        }
        if (two > mx)
        {
            if (neg % 2 == 0)
            {
                mx = two;
                p = {i, j - 1};
            }
            if (neg % 2 == 1)
            {
                int fs = -1;
                int ls = i;
                int cnt1 = 0;
                int cnt2 = 0;
                for (int k = i; k < j; k++)
                {
                    if (abs(v[k]) == 2)
                        cnt1++;
                    if (fs == -1 && v[k] < 0)
                    {
                        fs = k;
                        break;
                    }
                }
                for (int k = j - 1; k >= i; k--)
                {
                    if (abs(v[k]) == 2)
                        cnt2++;
                    if (v[k] < 0)
                    {
                        ls = k;
                        break;
                    }
                }
                int mn = min(cnt1, cnt2);
                if (two - mn > mx)
                {
                    mx = two - mn;
                    if (mn == cnt1)
                    {
                        p = {fs + 1, j - 1};
                    }
                    else
                    {
                        p = {i, ls - 1};
                    }
                }
            }
        }
        if (j >= n)
            break;
        i = j + 1;
    }
    if (p.first == -1 || p.second == -1 || p.first > p.second)
    {
        cout << 0 << " " << n << endl;
        return;
    }
    cout << p.first << " " << (n - 1 - p.second) << endl;
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