#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> odd, even;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] % 2 == 1)
        {
            odd.push_back(v[i]);
        }
        else
        {
            even.push_back(v[i]);
            cnt++;
        }
    }
    // sort(v.begin(), v.end());
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    if (odd.size() == 0 || odd.size() == n)
    {
        cout << 0 << endl;
        return;
    }
    int flag = 0;
    for (int i = 0; i < even.size(); i++)
    {
        int ind = upper_bound(odd.begin(), odd.end(), even[i]) - odd.begin();
        if (ind == odd.size())
        {
            flag = 1;
        }
        else
        {
            if (odd[odd.size() - 1] <= odd[odd.size() - 1] + even[i])
            {
                odd.push_back(odd[odd.size() - 1] + even[i]);
            }
        }
    }
    if (flag == 1)
    {
        cout << cnt + 1 << endl;
    }
    else
    {
        cout << cnt << endl;
    }
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