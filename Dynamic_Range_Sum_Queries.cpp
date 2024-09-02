#include <bits/stdc++.h>
using namespace std;
#define int long long int
void build(int ind, int low, int high, vector<int> &Seg, vector<int> &v)
{
    if (low == high)
    {
        Seg[ind] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, Seg, v);
    build(2 * ind + 2, mid + 1, high, Seg, v);
    Seg[ind] = Seg[2 * ind + 1] + Seg[2 * ind + 2];
}
int query(int ind, int low, int high, int l, int r, vector<int> &Seg)
{
    if (low >= l && r >= high)
    {
        return Seg[ind];
    }
    if (low > r || high < l)
        return 0;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r, Seg);
    int right = query(2 * ind + 2, mid + 1, high, l, r, Seg);
    return left + right;
}
void update(int ind, int low, int high, int pos, int val, vector<int> &Seg)
{
    if (low == high)
    {
        Seg[ind] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (mid >= pos)
    {
        update(2 * ind + 1, low, mid, pos, val, Seg);
    }
    else
    {
        update(2 * ind + 2, mid + 1, high, pos, val, Seg);
    }
    Seg[ind] = Seg[2 * ind + 1] + Seg[2 * ind + 2];
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n), Seg(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    build(0, 0, n - 1, Seg, v);
    while (q--)
    {
        int sg, l, r;
        cin >> sg >> l >> r;
        l--;
        r--;
        if (sg == 2)
        {
            cout << query(0, 0, n - 1, l, r, Seg) << endl;
        }
        else
        {
            update(0, 0, n - 1, l, r + 1, Seg);
        }
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