#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x]++;
        mp[y]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto x : mp)
    {
        if (x.second >= 2)
        {
            pq.push({v[x.first - 1], x.second - 1});
        }
    }
    vector<int> ans;
    ans.push_back(sum);
    for (int i = 0; i < n - 2; i++)
    {
        int x = pq.top().first;
        int y = pq.top().second;
        sum += x;
        if (y == 1)
            pq.pop();
        else
        {
            pq.pop();
            pq.push({x, y - 1});
        }
        ans.push_back(sum);
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