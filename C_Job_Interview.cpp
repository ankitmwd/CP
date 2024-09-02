#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int prog, tester;
    cin >> prog >> tester;
    int n = prog + tester + 1;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int j = 0; j < n; j++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    int np = 0, nt = 0;
    vector<int> v1, v2;
    // vector<int> ans;
    vector<int> vis(n + 1, 0);
    // vector<int> v1;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i] && prog >= v1.size())
        {
            v1.push_back(a[i]);
            vis[i] = 1;
            p = {a[i], b[i]};
        }
    }
    vector<int> temp;
    for (int i = n - 1; i >= 0; i--)
    {
        if (vis[i] == 0 && prog >= (v1.size() + temp.size()))
        {
            v1.push_back(a[i]);
            vis[i] = 1;
            p = {a[i], b[i]};
        }
    }
    // for (int i = temp.size() - 1; i >= 0; i--)
    // {
    // v1.push_back(temp[i]);
    // }
    int sum = 0;
    int sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 1)
            sum += a[i];
        else
            sum1 += b[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 1)
        {
            ans.push_back(sum - a[i] + sum1);
        }
        else
        {
            ans.push_back((sum - p.first) + sum1 - b[i] + p.second);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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