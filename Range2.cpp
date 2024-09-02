#include <bits/stdc++.h>
using namespace std;
#define int long long int

int query(int ind, int low, int high, vector<int> &Seg,  int pos)
{
    if (low > high)
        return 0;
    if (low == pos && high == pos)
    {
        return Seg[ind];
    }
    int mid = (low + high) / 2;
    int sum = 0;
    if (mid >= pos)
        sum += Seg[ind] + query(2 * ind + 1, low, mid, Seg, pos);
    else
        sum += Seg[ind] + query(2 * ind + 2, mid + 1, high, Seg, pos);
    return sum;
}
void Update(int ind, int low, int high, int l, int r, int val, vector<int> &Seg)
{
    if (low > high)
        return;
    if (low > r || high < l)
        return;
    if (low >= l && high <= r)
    {
        Seg[ind] += val;
        return;
    }
    int mid = (low + high) / 2;
    Update(2 * ind + 1, low, mid, l, r, val, Seg);
    Update(2 * ind + 2, mid + 1, high, l, r, val, Seg);
}

void build(int ind, int low, int high, vector<int> &seg, vector<int> &v)
{
    if (low > high)
        return;
    if (low == high)
    {
        seg[ind] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, seg, v);
    build(2 * ind + 2, mid + 1, high, seg, v);
    seg[ind] = 0;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), Seg(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    build(0, 0, n - 1, Seg, v);
    while (k--)
    {
        int sg;
        cin >> sg;
        if (sg == 2)
        {
            int pos;
            cin >> pos;
            pos--;
            cout << query(0, 0, n - 1, Seg, pos) << endl;
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            l--;
            r--;
            Update(0, 0, n - 1, l, r, val, Seg);
    
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