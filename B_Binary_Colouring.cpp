#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    int Num = n;
    vector<int> v(32, 0);
    cout << v.size() << endl;
    for (int i = 31; i >= 0; i--)
    {
        if (Num >= pow(2, i))
        {
            v[i] = 1;
            Num -= pow(2, i);
        }
    }
    Num = n;
    for (int i = 1; i <= 31; i++)
    {
        if (v[i] != 0 && v[i - 1] != 0)
        {
            // v[i] = 0;
            v[i - 1] = -1;
            while (v[i] != 0 && i < 32)
            {
                v[i] = 0;
                i++;
            }
            v[i] = 1;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        cout << v[i] << " ";
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