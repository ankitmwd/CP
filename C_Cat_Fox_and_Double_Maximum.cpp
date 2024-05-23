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
    vector<int> v1, v2;
    for (int i = 1; i < n - 1; i += 2)
    {
        v1.push_back(v[i]);
        v2.push_back(v[i - 1]);
    }
    v2.push_back(v[n - 1]);
    v2.push_back(v[n - 2]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    map<int, int> mp;
    int x = n;
    for (int i = 0; i < v1.size(); i++)
    {
        mp[v1[i]] = x;
        x--;
    }
    for (int i = 0; i < v2.size(); i++)
    {
        mp[v2[i]] = x;
        x--;
    }
    // cout << v1.size() << " " << v2.size() << endl;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        res[i] = mp[v[i]] + v[i];
    }
    int cnt1 = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (res[i] > res[i - 1] && res[i] > res[i + 1])
            cnt1++;
    }

    // Next
    vector<int> v3, v4;
    v4.push_back(v[0]);
    for (int i = 2; i < n; i += 2)
    {
        v3.push_back(v[i]);
        v4.push_back(v[i - 1]);
    }
    v4.push_back(v[n - 1]);
    sort(v4.begin(), v4.end());
    sort(v3.begin(), v3.end());
    map<int, int> mp1;
    x = n;
    for (int i = 0; i < v3.size(); i++)
    {
        mp1[v3[i]] = x;
        x--;
    }
    for (int i = 0; i < v4.size(); i++)
    {
        mp1[v4[i]] = x;
        x--;
    }
    vector<int> res1(n, 0);
    for (int i = 0; i < n; i++)
    {
        res1[i] = mp1[v[i]] + v[i];
    }
    int cnt2 = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (res1[i] > res1[i - 1] && res1[i] > res1[i + 1])
            cnt2++;
    }
    if (cnt1 >= cnt2)
    {
        // cout << "1" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << mp[v[i]] << " ";
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << mp1[v[i]] << " ";
        }
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