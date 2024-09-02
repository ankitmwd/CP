#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> neg, pos;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] >= 0)
        {
            pos.push_back(v[i]);
        }
        else
        {
            neg.push_back(v[i]);
        }
    }
    sort(neg.begin(), neg.end());
    sort(pos.rbegin(), pos.rend());
    if (pos.size() == 0 || neg.size() == 0)
    {
        cout << "No" << endl;
        return;
    }
    int mx = pos[0] - neg[0];
    // cout << "max :" << mx << endl;
    if (pos.size() > neg.size())
    {
        swap(pos, neg);
    }
    vector<int> ans;
    int sum = 0;
    int j = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (j != -1 && abs(sum + neg[j]) < mx)
        {
            ans.push_back(neg[j]);
            sum += neg[j];
            j++;
        }
        else if (k != -1 && abs(sum + pos[k]) < mx)
        {
            ans.push_back(pos[k]);
            sum += pos[k];
            k++;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
        if (j == neg.size())
            j = -1;
        if (k == pos.size())
            k = -1;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
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