#include <bits/stdc++.h>
using namespace std;
void update(int ind, int low, int high, int pos, vector<int> &seg)
{
    if (low == high)
    {
        seg[ind] = 1;
        return;
    }
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
int query(int ind, int low, int high, int l, int r, vector<int>&seg)
{
    if (low >= l && r >= high)
    {
        return seg[ind];
    }
    if (low > high || low > r || l > high)
        return 0;
    int mid = (low + high) / 2;
    return query(2 * ind + 1, low, mid, l, r, seg) + query(2 * ind + 2, mid + 1, high, l, r, seg);
}
void solve()
{
    unordered_map<int, int> mp, mp2;
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v1(n), v2(n), Seg(4 * n);
    vector<pair<int, int>> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp2[v[i]]++;
        v1[i] = mp2[v[i]];
        freq.push_back({v1[i], i});
    }
    for (int i = n - 1; i >= 0; i--)
    {
        mp[v[i]]++;
        v2[i] = mp[v[i]];
    }
    sort(freq.begin(), freq.end());
    map<pair<int, int>, int> pos;
    for (int i = 0; i < n; i++)
    {
        pos[{freq[i].first, freq[i].second}] = i;
    }
    long long int res = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = {v2[i], 1e8};
        int ind = upper_bound(freq.begin(), freq.end(), p) - freq.begin();
        if (ind >= n)
            continue;
        res += query(0, 0, n - 1, ind, n - 1, Seg);
        update(0, 0, n - 1, pos[{v1[i], i}], Seg);
    }
    cout << res << endl;
}
signed main()
{
    int t = 1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (t--)
    {
        solve();
    }
}