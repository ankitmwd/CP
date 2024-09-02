#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(string str, int k)
{
    int n = str.size();
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt++;
        if (i == n - 1 || str[i] != str[i + 1])
        {
            v.push_back(cnt);
            cnt = 0;
        }
    }
    int pos = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != k)
        {
            if (v[i] > k)
            {
                pos += (v[i] - k);
            }
            else
            {
                pos += v[i];
            }
            break;
        }
        pos += v[i];
    }
    return pos;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int pos = fun(str, k);
    string s = "";
    for (int i = pos; i < n; i++)
    {
        s += str[i];
    }
    for (int i = pos - 1; i >= 0; i--)
    {
        s += str[i];
    }
    if (fun(s, k) == n)
    {
        cout << pos << endl;
    }
    else
    {
        cout << -1 << endl;
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