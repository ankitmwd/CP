#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    int n1;
    cin >> n1;
    vector<int> v(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (v.size())
    {
        
    }
    cout << sum << endl;
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