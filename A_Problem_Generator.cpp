#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    map<char, int> mp;
    string s="ABCDEFG";
    for(int i=0;i<s.size();i++){
        mp[s[i]]=0;
    }
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        mp[str[i]]++;
    }
    
    int cnt = 0;
    for (auto x : mp)
    {
        if (x.second < k)
        {
            cnt += k - x.second;
        }
    }
    cout << cnt << endl;
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