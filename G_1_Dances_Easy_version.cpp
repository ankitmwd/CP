#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(1);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = n - 1;
    int j = n - 1;
    int cnt = 0;
    while (i >= 0)
    {
        if (b[j] > a[i])
        {
            j--;
            i--;
        }
        else
        {
            i--;
            cnt++;
        }
    }
    cout << cnt << endl;
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