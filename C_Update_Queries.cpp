#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    set<int> st;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        st.insert(x-1);
    }
    cin >> s2;
    sort(s2.begin(), s2.end());
    int j = 0;
    for (auto x : st)
    {
        s1[x] = s2[j];
        j++;
    }
    cout << s1 << endl;
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