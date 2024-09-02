#include <bits/stdc++.h>
using namespace std;
#define int long long int

int query(int ind, int low, int high, vector<int> &Seg, vector<int> &Lazy, int pos)
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
        return Seg[ind] + query(2 * ind + 1, low, mid, Seg, Lazy, pos);
    else
        return Seg[ind] + query(2 * ind + 2, mid + 1, high, Seg, Lazy, pos);
}
void Update(int ind, int low, int high, int l, int r, vector<int> &Lazy, int val, vector<int> &Seg)
{
    if (low > high)
        return;
    if (low == l && high == r)
    {
        Seg[ind] += val;
        return;
    }
    int mid = (low + high) / 2;
    Update(2 * ind + 1, low, mid, l, r, Lazy, val, Seg);
    Update(2 * ind + 2, mid + 1, high, l, r, Lazy, val, Seg);
}
const int N = 2e5;
int t[4 * N];
void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        t[v] += add;
    }
    else
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

int get(int v, int tl, int tr, int pos)
{
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v * 2, tl, tm, pos);
    else
        return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), Seg(4 * n), Lazy(4 * n, 0LL);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        A[i] = v[i];
    }
    // build(0, 0, n - 1, Seg, v);
    build(A, 1, 0, n - 1);
    while (k--)
    {
        int sg;
        cin >> sg;
        if (sg == 2)
        {
            int pos;
            cin >> pos;
            pos--;
            // cout << "Enter Here" << endl;
            // cout << query(0, 0, n - 1, Seg, Lazy, pos) << endl;
            cout<<get(1,0,n-1,pos)<<endl;
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            l--;
            r--;
            // Update(0, 0, n - 1, l, r, Lazy, val, Seg);
            update(1,0,n-1,l,r,val);
            // cout << "will do it" << endl;
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