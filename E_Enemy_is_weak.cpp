#include <bits/stdc++.h>
using namespace std;
#define int long long int
void update(int ind, int low, int high, int pos, vector<int> &seg)
{
    if (low == high)
    {
        seg[ind] += 1;
        return;
    }
    if (low > high)
        return;

    int mid = (low + high) / 2;
    if (mid >= pos)
    {
        update(2 * ind + 1, low, mid, pos, seg);
    }
    else
    {
        update(2 * ind + 2, mid + 1, high, pos, seg);
    }
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
int query(int ind, int low, int high, int l, int r, vector<int> &seg)
{
    if (low >= l && r >= high)
    {
        return seg[ind];
    }
    int mid = (low + high) / 2;
    int sum = 0;
    if (low > high || low > r || l > high)
        return 0;

    sum += query(2 * ind + 1, low, mid, l, r, seg);

    sum += query(2 * ind + 2, mid + 1, high, l, r, seg);

    return sum;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), v1(n), Seg(4 * n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = -v[i];
        v1[i] = v[i];
    }
    sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++)
    {
        int ind = lower_bound(v1.begin(), v1.end(), v[i]) - v1.begin();
        // cout << ind << endl;
        // ind--;
        update(0, 0, n - 1, ind, Seg);
        cout << query(0, 0, n - 1, 0, ind, Seg) << endl;
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