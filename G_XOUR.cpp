#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    map<int, int> mp;
    vector<pair<int, int>> v2;

    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
        // mp[v1[i]] = i;
        v2.push_back({v1[i], i});
    }
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = {v1[i], -1};
        int ind = upper_bound(v2.begin(), v2.end(), p) - v2.begin();
        int pw = ceil(log2(v1[i]));
        int val = pow(2, pw);
        cout << val << endl;
        for (int j = ind; j < n && v2[j].first <= max(val, (int)4); j++)
        {
            int ind1 = v2[j].second;
            if ((v1[i] ^ v1[ind1]) < 4 && i > ind1)
            {
                cout << i << " " << ind1 << endl;
                swap(v1[i], v1[ind1]);
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v1[i] << " ";
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