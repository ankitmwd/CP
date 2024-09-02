#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    int open = n / 2;
    int close = n / 2;
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            open--;
        else if (str[i] == ')')
            close--;
    }
    stack<int> st;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (str[i - 1] == '(')
        {
            st.push(i);
        }
        else if (str[i - 1] == ')')
        {
            ans += (i - st.top());
            st.pop();
        }
        else
        {
            if (st.empty())
            {
                st.push(i);
            }
            else if (close > 0)
            {
                ans += (i - st.top());
                st.pop();
                close--;
            }
            else
            {
                st.push(i);
            }
        }
    }
    cout << ans << endl;
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