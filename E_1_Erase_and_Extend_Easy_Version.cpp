#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int ind = n;
    string temp = "";
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[j] < str[i])
        {
            ind = j;
            break;
        }
        else if (str[j] == str[i] && i != j)
        {
            j++;
        }
    }
    for (int i = 0; i <= min(n - 1, j); i++)
    {
        temp += str[i];
    }
    string ans = "";

    while ((ans.size()) <= k)
    {
        ans += temp;

        temp = ans;
    }
    string ans1 = "";
    for (int i = 0; i < k; i++)
    {
        ans1 += ans[i];
    }

    cout << ans1 << endl;
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