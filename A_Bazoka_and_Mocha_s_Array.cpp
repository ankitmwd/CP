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
    for (int ind = 0; ind < n; ind++)
    {

        int sign = 1;
        vector<int> v1;
        for (int i = ind; i < n; i++)
        {
            v1.push_back(v[i]);
        }
        for (int i = 0; i < ind; i++)
        {
            v1.push_back(v[i]);
        }
        for (int i = 1; i < v1.size(); i++)
        {
            if (v1[i - 1] > v1[i])
                sign = 0;
        }
        if (sign)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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