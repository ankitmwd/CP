#include <bits/stdc++.h>
using namespace std;
// #define int long long int
#define pii pair<int, int>
#define F first
#define S second
#define MOD 1e9 + 7
pii merge(pii v1, pii v2)
{
    if (v1.F == v2.F)
    {
        if (v1.F == 0)
            return {0, 1};

        pii result = {v1.F, (v1.S + v2.S)};
        if (result.S >= MOD)
            result.S -= MOD;
        return result;
    }
    return max(v1, v2);
}
pair<int, int> query(int ind, int low, int high, int l, int r, vector<pair<int, int>> &seg)
{
    if (low >= l && r >= high)
    {
        return seg[ind];
    }
    if (low > r || l > high || low > high)
        return {0, 1};
    int mid = (low + high) / 2;
    pair<int, int> left = query(2 * ind + 1, low, mid, l, r, seg);
    pair<int, int> right = query(2 * ind + 2, mid + 1, high, l, r, seg);
    return merge(left, right);
}
void update(int ind, int low, int high, int pos, pair<int, int> p, vector<pair<int, int>> &seg)
{
    if (low == high)
    {
        seg[ind] = p;
        return;
    }
    int mid = (low + high) / 2;
    if (mid >= pos)
    {
        update(2 * ind + 1, low, mid, pos, p, seg);
    }
    else
    {
        update(2 * ind + 2, low, mid, pos, p, seg);
    }
    seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> v1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v1.push_back({v[i], i});
    }
    vector<pair<int, int>> Seg(4 * n, {0, 1});
    sort(v1.begin(), v1.end());
    vector<int> pos(n, 0);
    for (int i = 0; i < n; i++)
    {
        pos[v1[i].second] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int lb = lower_bound(v1.begin(), v1.end(), make_pair(v[i], -1)) - v1.begin();
        pair<int, int> p;
        if (lb > 0)
        {
            p = query(0, 0, n - 1, 0, lb - 1, Seg);
        }
        pair<int, int> p1 = {max(1, p.first + 1), max(1, p.second)};
        update(0, 0, n - 1, pos[i], p1, Seg);
    }
    pair<int, int> res = query(0, 0, n - 1, 0, n - 1, Seg);
    cout << res.F << " " << res.S << endl;
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