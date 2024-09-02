#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, jump, swim;
    cin >> n >> jump >> swim;
    int last = 0;
    string s;
    cin >> s;
    vector<char> v(n + 1);
    v[0] = 'L';
    for (int i = 0; i < n; i++)
    {
        v[i + 1] = s[i];
    }
    
    for (int i = 0; i <= n; i++)
    {
        if (i + 1 <= n && v[i] == 'L' && v[i + 1] != 'L')
        {
            int j = i + 1;
            while (v[j] != 'L' && (j - i) < jump)
            {
                j++;
            }
            i = j - 1;
        }
        else if (v[i] == 'W')
        {
            swim--;
            // i++;
        }usi
        else if (v[i] == 'C')
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (swim >= 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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