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
    vector<int> v1;
    v1.push_back(v[0]);
    v1.push_back(v[1]);

    sort(v1.begin(), v1.end());
    int ans = v1[0];
    if (v.size() >= 3)
    {
        v1.push_back(v[2]);
        sort(v1.begin(), v1.end());
        ans = max(ans, v1[1]);
    }
    for (int i = 3; i < n; i++)
    {
        int ind = 0;
        if (v[i - 3] == v1[0])
        {
            ind = 0;
        }
        else if (v[i - 3] == v1[1])
        {
            ind = 1;
        }
        else
        {
            ind = 2;
        }
        v1.erase(v1.begin() + ind);
        v1.push_back(v[i]);
        sort(v1.begin(), v1.end());
        // cout << v1.size() << endl;
        ans = max(ans, v1[1]);
        // cout << ans << endl;
    }
    cout << ans << endl;
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