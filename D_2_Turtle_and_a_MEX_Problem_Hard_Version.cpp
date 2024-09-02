#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<int> temp;
        while (x--)
        {
            int y;
            cin >> y;
            temp.push_back(y);
        }
        sort(temp.begin(), temp.end());
        int cnt = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == cnt)
            {
                cnt++;
            }
        }
        temp.push_back(cnt);
        sort(temp.begin(), temp.end());
        cnt = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == cnt)
            {
                cnt++;
            }
        }
        v.push_back(cnt);
    }
    sort(v.rbegin(), v.rend());
    int mx = 0;
    int mx1 = v[0];
    int mx2 = 0;
    if (v.size() > 1)
    {
        mx2 = v[1];
    }
    int ans = 0;
    while (mx <= mx1 && mx < (m + 1))
    {
        ans += mx1;
        mx++;
        if (mx == m + 1)
            break;
        if (mx >= mx2)
        {
            ans += (mx);
            mx++;
        }
        else
        {
            ans += mx2;
            mx++;
        }
    }

    if (mx >= (m + 1))
    {
        cout << ans << endl;
    }
    else
    {
        // cout << "second" << endl;
        int res = (m * (m + 1)) / 2;
        int Num = max(mx-1, 0LL);
        int mn = (Num * (Num + 1)) / 2;
        cout << (res - mn) + ans << endl;
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