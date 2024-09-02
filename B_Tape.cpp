#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool bin(int ind, vector<int> &v, int k)
{
    int n = v.size();
    if (k <= 0)
        return 1e8;
    if (ind >= n)
        return 0;
    int left = 1e8;
    for (int i = ind + 1; i < n; i++)
    {
        left = min(left, bin(i + 1, v, k - 1) + abs(v[i] - v[ind] + 1));
    }
    int right = bin(ind + 1, v, k - 1) + 1;
    cout << left << " " << right << endl;
    return min(left, right);
}
void solve()
{
    int n, high, k;
    cin >> n >> high >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << bin(0, v, k - 2);
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}