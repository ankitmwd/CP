#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v1(n, vector<int>(m));
    vector<vector<int>> v2(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v1[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v2[i][j];
        }
    }
    int mtc = 0;
    sort(v1.begin(), v1.end());
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v1[0][i] == v2[j][0])
            {
                mtc = j;
                // cout << "match : " << mtc << endl;
                break;
            }
        }
    }
    vector<pair<int, int>> a1, a2;
    for (int i = 0; i < m; i++)
    {
        a1.push_back({v1[0][i], i});
    }
    for (int i = 0; i < m; i++)
    {
        a2.push_back({v2[mtc][i], i});
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    vector<vector<int>> v3 = v2;
    set<pair<int, int>> st;
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        int mn = a1[i].second;
        int mx = a2[i].second;
        if (mn == mx)
            continue;
        // cout << " swap " << mn << " " << mx << endl;
        for (int j = 0; j < n; j++)
        {
            v3[j][mn] = v2[j][mx];
        }
    }
    sort(v3.begin(), v3.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v1[i][j] != v3[i][j])
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