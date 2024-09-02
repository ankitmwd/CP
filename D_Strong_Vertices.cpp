#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    int mx = -1e15;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        ans[i] = v1[i] - v2[i];
        mx = max(mx, ans[i]);
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == mx)
        {
            v.push_back(i + 1);
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
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