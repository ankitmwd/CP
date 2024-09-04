#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> sum(n, 0);
    multiset<int> mt;
    set<int> st;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < k; i++)
    {
        mt.insert(v[i]);
        st.insert(v[i]);
        sum[i] = st.size();
    }
    for (int i = k; i < n; i++)
    {
        mt.erase(mt.find(v[i - k]));
        if (mt.find(v[i - k]) == mt.end())
        {
            st.erase(v[i]);
        }
        mt.insert(v[i]);
        st.insert(v[i]);
        sum[i] = st.size();
    }
    for (int i = 0; i < n; i++)
    {
        cout << sum[i] << " ";
    }
    cout << endl;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}