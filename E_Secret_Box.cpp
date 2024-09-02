#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(vector<int> v1, vector<int> v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int n = 3;
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (v1[i] < v2[i])
            return 0;
        ans *= (v1[i] - v2[i] + 1);
    }
    return ans;
}
void solve()
{
    int z, x, y, vol;
    cin >> x >> y >> z >> vol;
    int xrem = 1, yrem = 1, zrem = 1;
    vector<int> v = {x, y, z};
    sort(v.begin(), v.end());
    int mx = 0;
    for (int i = 1; i <= sqrt(vol); i++)
    {
        if (vol % i == 0)
        {
            int fact = i;
            int y = vol / i;
            for (int j = 1; j <= sqrt(y); j++)
            {
                if (y % j == 0)
                {
                    int fact2 = j;
                    int fact3 = y / j;
                    vector<int> v2 = {fact, fact2, fact3};
                    mx = max(mx, fun(v, v2));
                }
            }
        }
    }
    cout << mx << endl;
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