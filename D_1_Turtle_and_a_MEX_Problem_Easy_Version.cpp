#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (st.find(v[i]) != st.end())
        {
            cout << "FOUND" << endl;
        }
        else
        {
            cout << "NOT FOUND" << endl;
        }
        st.insert(v[i]);
    }
    
}