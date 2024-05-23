#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> v2[j];
    }
    map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        mp[abs(v1[i] - v2[i])]++;
        sum += abs(v1[i] - v2[i]);
    }
    if (k1 + k2 >= sum)
    {
        int rm = k1 + k2 - sum;
        if (rm % 2 == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return;
    }
    priority_queue<pair<int, int>> pq;
    for (auto x : mp)
    {
        pq.push({x.first, x.second});
    }
    int tot = k1 + k2;
    int ans = 0;
    while (!pq.empty())
    {
        int x = pq.top().first;
        int tm = pq.top().second;
        pq.pop();
        if (pq.empty())
        {
            int we_hv = x * tm;
            if (we_hv >= tot)
            {
                we_hv -= tot;
                int rem = we_hv % tm;
                int x = we_hv / tm;
                for (int i = 0; i < rem; i++)
                {
                    ans += ((x + 1) * (x + 1));
                }
                for (int i = 0; i < tm - rem; i++)
                {
                    ans += (x * x);
                }
                cout << ans << endl;
                return;
            }
            else
            {
                we_hv = tot % 2;
                cout << we_hv * we_hv << endl;
                return;
            }
        }
        int x2 = pq.top().first;
        int tm2 = pq.top().second;
        int diff = (x - x2) * tm;
        if (tot >= diff)
        {
            pq.pop();
            pq.push({x2, tm + tm2});
            tot -= diff;
        }
        else
        {
            diff = x * tm;
            diff -= tot;
            int rem = diff % tm;
            int x = diff / tm;
            for (int i = 0; i < rem; i++)
            {
                ans += ((x + 1) * (x + 1));
            }
            for (int i = 0; i < tm - rem; i++)
            {
                ans += (x * x);
            }
            while (!pq.empty())
            {
                int fs = pq.top().first;
                int sc = pq.top().second;
                for (int j = 0; j < sc; j++)
                {
                    ans += (fs * fs);
                }
                pq.pop();
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}