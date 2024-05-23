#include <bits/stdc++.h>
using namespace std;
#define int long long int
char solve()
{
    string str;
    cin >> str;
    int pos;
    cin >> pos;
    pos--;
    int sz = str.size();
    int n = sz;
    vector<char> st;
    bool ok = pos < n;
    str += '$';
    for (auto c : str)
    {
        while (!ok && st.size() > 0 && st.back() > c)
        {
            pos -= n;
            n--;
            st.pop_back();
            if (pos < n)
                ok = 1;
        }
        st.push_back(c);
    }
    return st[pos];
}
signed main()
{
    int t;
    cin >> t;
    string ans = "";
    while (t--)
    {
        ans += solve();
    }
    cout << ans << endl;
}