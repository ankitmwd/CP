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
    vector<vector<int>> v1;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(v[i]);
        if (temp.size() == 3)
        {
            v1.push_back(temp);
            // cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
            temp.erase(temp.begin() + 0);
        }
    }
    int n1 = v1.size();
    map<pair<int, int>, int> mp1;
    map<pair<int, int>, int> mp2;
    map<pair<int, int>, int> mp3;
    map<vector<int>, int> mpcnt;
    set<pair<int, pair<int, int>>> st;
    for (int i = 0; i < n1; i++)
    {
        mp1[{v1[i][0], v1[i][1]}]++;
        mp2[{v1[i][1], v1[i][2]}]++;
        mp3[{v1[i][0], v1[i][2]}]++;
        vector<int> temp2 = v1[i];
        mpcnt[temp2]++;
        // st.insert({v1[i][0], {v1[i][1], v1[i][2]}});
    }
    int eq = 0;
    int cnt = 0;
    for (auto x : mp1)
    {
        int y = x.second;
        cnt += (y * (y - 1)) / 2;
    }
    for (auto x : mp2)
    {
        int y = x.second;
        cnt += (y * (y - 1)) / 2;
    }
    for (auto x : mp3)
    {
        int y = x.second;
        cnt += (y * (y - 1)) / 2;
    }
    for (auto x : mpcnt)
    {
        int y = x.second;
        eq += (y * (y - 1)) / 2;
    }
    // cout <
    // int eq1 = 3 * (((eq + 1) * eq) / 2);
    cout << (cnt - 3LL * eq) << endl;
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