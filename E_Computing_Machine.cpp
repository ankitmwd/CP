#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    string s3 = s1;
    vector<int> chan(n + 1, 0);
    for (int i = 0; i < n - 2; i++)
    {
        if (s1[i] == s1[i + 2] && s1[i] == '0')
        {
            s2[i] = '1';
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (s2[i] == s2[i + 2] && s2[i] == '1')
        {
            if (s1[i] == '0')
                chan[i + 1] = 1;
            s1[i] = '1';
        }
    }
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        if (s1[i] == '1')
            x = 1;
        pref[i + 1] += (pref[i] + x);
        chan[i + 1] += chan[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int r, l;
        cin >> l >> r;
        int plus = 0;
        if (s3[r - 1] == '0' && s1[r - 1] == '1')
        {
            plus++;
        }
        if (r - 2 >= l && s3[r - 2] == '0' && s1[r - 2] == '1')
        {
            plus++;
        }
        if (l + 1 < r - 2 && s3[l + 1] == '0' && s1[l + 1] == '1')
        {
            plus++;
        }
        if (l + 2 < r - 2 && s3[l + 2] == '0' && s1[l + 2] == '1')
        {
            plus++;
        }
        int z = 0;
        if (l - 2 >= 0)
        {
            z = chan[l - 2];
        }
        cout << pref[r] - pref[l - 1] - plus - z << endl;
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