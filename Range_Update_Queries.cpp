#include <bits/stdc++.h>
using namespace std;
#define int long long int
void build(int ind, int low, int high, vector<int> &Seg, vector<int> &v)
{
    if (low == high)
    {
        Seg[ind] = v[low];
    }
    int mid = (high + low) / 2;
    build(2 * ind + 1, low, mid, Seg, v);
    build(2 * ind + 2, mid + 1, high, Seg, v);
    Seg[ind] = Seg[ind];
}
int query(int ind, int low, int high, vector<int> &Seg, vector<int> &Lazy, int pos)
{
    if (low == high)
    {
        return Seg[ind];
    }
    int mid = (low + high) / 2;
    if (mid >= pos)
    {
        return Seg[ind] + query(2 * ind + 1, low, mid, Seg, Lazy, pos);
    }
    else
    {
        return Seg[ind] + query(2 * ind + 2, mid + 1, high, Seg, Lazy, pos);
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), Seg(4 * n), Lazy(4 * n, 0LL);
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
            cout << query(0, 0, n - 1, Seg, Lazy, pos);
        }
        else
        {
            cout << "will do it" << endl;
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