#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n)
    {
        v.push_back(n % 10);
        n = n / 10;
    }
    for (int i = 1; i < v.size(); i++)
    {
        int x = v[i - 1] + v[i] * 10;
        if (x < 9 || v[i - 1] == 9)
        {
            cout << "NO" << endl;
            return;
        }
        if (v[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
        v[i]--;
        if (i == v.size() - 1)
        {
            if (x >= 19)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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