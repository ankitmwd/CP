#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int m = 30;
    vector<vector<int>> v(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> v[0][i + 1];
    }
    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            v[j][i] = v[j - 1][v[j - 1][i]];
        }
    }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int ans = x;
        for (int i = 0; i < 31; i++)
        {
            if (k & (1 << i))
            {
                ans = v[i][ans];
            }
        }
        cout << ans << endl;
    }
    return 0;
}