#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        while (!st.empty())
        {
            auto ele = st.begin();
            int val = *ele;
            if (val < x)
                st.erase(ele);
            else
                break;
        }
        st.insert(y);
        if (st.size() > 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}