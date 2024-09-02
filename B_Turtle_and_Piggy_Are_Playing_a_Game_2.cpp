#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int l = 0;
    int h = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int turn = 1;
    sort(v.begin(),v.end());
    while (h >= l)
    {
        if (turn)
        {
            l++;
            turn=0;
        }
        else
        {
            
            h--;
            turn=1;
        }
        if (l == h)
        {
            cout << v[l] << endl;
            return;
        }
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