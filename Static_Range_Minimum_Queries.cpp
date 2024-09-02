#include <bits/stdc++.h>
using namespace std;
#define int long long int

void build(int ind, int low, int high, vector<int> &Seg, vector<int> &Arr)
{
    if (low == high)
    {
        Seg[ind] = Arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, Seg, Arr);
    build(2 * ind + 2, mid + 1, high, Seg, Arr);
    Seg[ind] = min(Seg[2 * ind + 1], Seg[2 * ind + 2]);
}
int query(int ind, int low, int high, int l, int r, vector<int> &Seg, vector<int> &Arr)
{
    if (l <= low && r >= high)
    {
        return Seg[ind];
    }
    if (low > r || high < l)
        return 1e18;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r, Seg, Arr);
    int right = query(2 * ind + 2, mid + 1, high, l, r, Seg, Arr);
    return min(left, right);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> Arr(n);
    vector<int> Seg(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    build(0, 0, n - 1, Seg, Arr);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << query(0, 0, n - 1, x, y, Seg, Arr) << endl;
    }
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