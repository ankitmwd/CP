#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    n++;
    vector<int> deg(n, 0);
    int x = 1;
    set<pair<int, int>> st;
    while (x)
    {
        for (int i = 1; i < n; i++)
        {
            if (deg[i] == 0)
            {
                for (int j = i + 1; j < n; j++)
                {
                    cout << "? " << i << " " << j << endl;
                    int x1;
                    cin >> x1;
                    if (x1 == i || x1 == j)
                    {
                        st.insert({min(j, i), max(i, j)});
                    }
                    else if (x1 == -1)
                    {
                        break;
                        x = 0;
                    }
                    else if (x1 != -1)
                    {
                        st.insert({{min(x1, i), max(x1, i)}});
                        st.insert({{min(x1, j), max(x1, j)}});
                        deg[x1] = 2;
                    }
                    cout.flush();
                }
            }
        }
    }
    cout << "! ";
    for (auto x : st)
    {
        cout << x.first << " " << x.second << " ";
    }
    cout << endl;
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