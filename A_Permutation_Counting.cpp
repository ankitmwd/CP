#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> mp;
    int sm = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
        sm = min(sm, v[i]);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto x : mp)
    {
        pq.push({x.first, x.second});
    }
    int equal = mp[sm];
    while (1)
    {
        int x = pq.top().first;
        int cnt = pq.top().second;
        if (pq.size() == 1)
        {
            int y = k / cnt;
            sm = x + y;
            equal = (cnt - k % cnt);
            break;
        }
        pq.pop();
        int y = pq.top().first;
        int cnt2 = pq.top().second;
        pq.pop();
        if ((y - x) * cnt <= k)
        {
            k -= ((y - x) * cnt);
            pq.push({y, cnt + cnt2});
        }
        else
        {
            int y = k / cnt;
            sm = x + y;
            equal = (cnt - k % cnt);
            break;
        }
    }
    // cout << sm << " " << equal << endl;
    cout << sm + (sm - 1) * (equal - 1) + (n - equal) * sm << endl;
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