#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    map<int, int> mp;
    mp[0] = 1;
    vector<int> v(n);
    for (int i = 0; i < str.size(); i++)
    {
        int x = str[i] - '0';
        v[i] = x;
    }
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        mp[v[i] - i - 1]++;
    }
    int cnt = 0;
    for (auto y : mp)
    {
        int x = y.second;
        cnt += (x * (x - 1)) / 2;
    }
    cout << cnt << endl;
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