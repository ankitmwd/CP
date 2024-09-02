#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    string str1, str2;
    cin >> str1 >> str2;
    swap(str1[0], str2[0]);
    cout << str1 << " " << str2 << endl;
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