#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i] / 4].push(v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << mp[v[i] / 4].top() << " ";
        mp[v[i] / 4].pop();
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