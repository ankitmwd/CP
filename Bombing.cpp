#include <bits/stdc++.h>
using namespace std;
#define int long long int
void Update(int ind, int low, int high, int pos, vector<int> &seg, int fac)
{
    if (low == high)
    {
        seg[ind] += fac;
        return;
    }
    if (low > high)
        return;
    int mid = (low + high) / 2;
    if (mid >= pos)
        Update(2 * ind + 1, low, mid, pos, seg, fac);
    else
        Update(2 * ind + 2, mid + 1, high, pos, seg, fac);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
int query(int ind, int low, int high, int pos, vector<int> &seg)
{
    if (low == high)
    {
        return seg[ind];
    }
    if (low > high)
        return 0;
    int mid = (low + high) / 2;
    int sum = 0;
    if (mid >= pos)
    {
        sum += query(2 * ind + 1, low, mid, pos, seg);
    }
    else
    {
        sum += query(2 * ind + 2, mid + 1, high, pos, seg);
    }
    return sum;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    int N = 1e5 + 10;
    vector<int> Seg = vector<int>(N);
    vector<pair<int, int>> v;
    while (q--)
    {
        char sign;
        cin >> sign;
        if (sign == 'P')
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            Update(0, 0, n - 1, x - 1, Seg, 1);
            Update(0, 0, n - 1, y + 1, Seg, -1);

            v.push_back({x, y});
        }
        else if (sign == 'M')
        {
            int ind, dis;
            cin >> ind >> dis;
            int x = v[ind - 1].first;
            int y = v[ind - 1].second;
            Update(0, 0, n - 1, x - 1, Seg, -1);
            Update(0, 0, n - 1, y + 1, Seg, 1);

            x += dis;
            y += dis;
            Update(0, 0, n - 1, x - 1, Seg, 1);
            Update(0, 0, n - 1, y + 1, Seg, -1);
        }
        else
        {
            int pos;
            cin >> pos;
            pos--;
            cout << query(0, 0, n - 1, pos, Seg) << endl;
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