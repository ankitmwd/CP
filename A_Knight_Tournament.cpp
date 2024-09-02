#include <bits/stdc++.h>
using namespace std;
#define int long long int
void update(int ind, int low, int high, int l, int r, int pos, vector<int> &Seg)
{
    if (low >= l && r >= high && Seg[ind] == 0)
    {
        Seg[ind] = pos + 1;
        return;
    }
    if (low > high || low > r || high < l)
        return;
    int mid = (low + high) / 2;
    update(2 * ind + 1, low, mid, l, r, pos, Seg);
    update(2 * ind + 2, mid + 1, high, l, r, pos, Seg);
}
void update1(int ind, int low, int high, int pos, vector<int> &Seg)
{
    if (low == high && low == pos && Seg[ind] == pos + 1)
    {
        Seg[ind] = 0;
        return;
    }
    if (low == high && low == pos)
        return;
    if (low > high)
        return;
    int mid = (low + high) / 2;
    if (mid >= pos)
        update1(2 * ind + 1, low, mid, pos, Seg);
    else
        update1(2 * ind + 2, mid + 1, high, pos, Seg);
}
int query(int ind, int low, int high, int pos, vector<int> &Seg)
{
    if (low == pos && high == pos)
    {
        return Seg[ind];
    }
    if (low > high)
        return 0;
    int mid = (low + high) / 2;
    int sum = 0;
    if (mid >= pos)
        sum += query(2 * ind + 1, low, mid, pos, Seg);
    else
        sum += query(2 * ind + 2, mid + 1, high, pos, Seg);
    return sum;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n), Seg(4 * n, 0);
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(i);
    }
    map<int, int> mp;
    while (q--)
    {
        int l, r, wn;
        cin >> l >> r >> wn;
        auto it = st.lower_bound(l);
        while (*it <= r)
        {
            mp[*it] = wn;
            st.erase(it);
            it = st.lower_bound(l);
        }
        st.insert(wn);
        mp[wn] = 0;
        // update(0, 0, n - 1, l, r, wn, Seg);
        // update1(0, 0, n - 1, wn, Seg);
    }
    for (int i = 0; i < n; i++)
    {
        cout << mp[i + 1] << " ";
    }
    cout << endl;
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