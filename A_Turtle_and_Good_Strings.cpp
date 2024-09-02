#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]==s[n-1]){
        cout<<"No"<<endl;
    }
    else{
        cout<<"YES"<<endl;
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