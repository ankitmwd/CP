#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
}
signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    // priority_queue<int> pq;
    int sum = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        mx = max(mx, v[i]);
    }

    if (sum % 2 == 0 && (sum >= 2LL * mx))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}