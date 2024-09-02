#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> dis(k), tim(k);
    for (int i = 0; i < k; i++)
    {
        cin >> dis[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> tim[i];
    }
    vector<int> ans;
    while (q--)
    {
        int dist = 0;
        int time = 0;
        int x;
        cin >> x;
        int ind = upper_bound(dis.begin(), dis.end(), x) - dis.begin();
        if (ind >= k)
            ind--;
        if (ind > 0)
        {
            dist = dis[ind - 1];
            time = tim[ind - 1];
        }
        int timeTaken = time + ((tim[ind] - time) * (x - dist)) / (dis[ind] - dist);
        ans.push_back(timeTaken);
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