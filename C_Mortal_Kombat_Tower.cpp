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
    bool on = 1;
    int i = 0;
    int skip = 0;
    while (i < n)
    {
        if (on == 1)
        {
            if (v[i] == 1)
            {
                skip++;
                i++;
            }
            while (i<n && v[i] == 0)
            {
                i++;
            }
            on = !on;
        }
        else
        {
            if (i + 1 < n && v[i + 1] == 1)
            {
                i = i + 2;
            }
            else
                i++;
            on = !on;
        }
    }
    cout << skip << endl;
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