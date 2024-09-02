#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(int ind, string s)
{
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == ind)
        {
            int x = (s[i] - '0') * 10 + (s[i + 1] - '0');
            v.push_back(x);
            i++;
        }
        else
        {
            v.push_back((s[i] - '0'));
        }
    }
    int ans = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (ans * v[i] <= max(ans,v[i]))
        {
            ans *= v[i];
        }
        else
        {
            ans += v[i];
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int mn = 1e18;
    for (int i = 0; i < n - 1; i++)
    {
        mn = min(fun(i, str), mn);
    }
    cout << mn << endl;
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