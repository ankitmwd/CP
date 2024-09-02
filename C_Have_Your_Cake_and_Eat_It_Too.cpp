#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(3, vector<int>(n + 1));
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[0][i + 1];

        sum += v[0][i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[1][i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[2][i + 1];
    }
    sum = ceil((sum * 1.0) / 3);
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int prev = 1;
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    map<pair<int, int>, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        sum1 += v[0][i];
        sum2 += v[1][i];
        sum3 += v[2][i];
        int sign = 0;
        if (sum1 >= sum)
        {
            mp[{prev, i}].push_back(1);
            sign = 1;
        }
        if (sum2 >= sum)
        {
            mp[{prev, i}].push_back(2);

            sign = 1;
        }
        if (sum3 >= sum)
        {
            mp[{prev, i}].push_back(3);

            sign = 1;
        }
        if (sign)
        {
            prev = i + 1;
            sum1 = sum2 = sum3 = 0;
        }
    }
    vector<vector<int>> ans1(4);
    map<pair<int, int>, int> mp1;
    while (st.size() > 0)
    {
        int cnt = INT_MAX;
        int sign = 0;
        for (auto x : mp)
        {
            if (mp1[x.first] == 0)
            {
                cnt = min(cnt, (int)x.second.size());
                sign = 1;
            }
        }
        for (auto x : mp)
        {
            int bk = 0;
            if (cnt == x.second.size())
            {
                for (auto Arr : x.second)
                {
                    if (st.find(Arr) != st.end())
                    {
                        ans1[Arr] = {x.first.first, x.first.second};
                        cout << mp1[x.first] << endl;
                        cout << x.first.first << " " << x.first.second << endl;
                        st.erase(st.find(Arr));
                        bk = 1;
                        mp1[x.first] = 1;
                        break;
                    }
                }
            }
            if (bk)
                break;
        }
        if (sign == 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        cout << ans1[i][0] << " " << ans1[i][1] << " ";
    }
    cout << endl;
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