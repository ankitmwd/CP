#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1e15));
    // vector<vector<int>> v(n + 1, vector<int>(n + 1, 1e15));
    int x, y, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> wt;
        dis[x][y] = min(dis[x][y], wt);
        dis[y][x] = min(dis[y][x], wt);
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int via = 1; via <= n; via++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][via] + dis[via][j], dis[i][j]);
            }
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (dis[x][y] >= 1e14)
        {
            cout << -1 << endl;
        }
        else
            cout << dis[x][y] << endl;
    }
}