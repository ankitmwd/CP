#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        mp[b[i]]++;
    }
    int m;
    cin >> m;
    vector<int> v2(m);
    map<int, int> tot;
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
        tot[v2[i]]++;
    }
    if (mp[v2[m - 1]] == 0)
    {
        cout << "NO" << endl;
        return;
    }
    // tot[v2[m - 1]]--;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (tot[b[i]] > 0)
                tot[b[i]]--;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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