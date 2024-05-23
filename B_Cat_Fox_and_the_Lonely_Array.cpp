#include <bits/stdc++.h>
using namespace std;
#define int long long int
int sz = 25;
bool fun(int k, vector<vector<int>> &v, int n)
{

    vector<int> temp = v[k - 1];
    for (int i = k; i < n; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (temp[j] >= 1 && (v[i][j] - v[i - (k)][j]) >= 1)
            {
            }
            else if (temp[j] == 0 && (v[i][j] - v[i - (k)][j]) == 0)
            {
            }
            else
                return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    // int xr = 0;
    vector<vector<int>> v1(n, vector<int>(sz, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < sz; j++)
        {
            int x = pow(2, j);
            if (x & v[i])
            {
                v1[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            v1[i][j] += v1[i - 1][j];
        }
    }

    int l = 1;
    int h = n;
    int ans = h;
    while (h >= l)
    {
        int mid = (l + h) / 2;
        if (fun(mid, v1, n))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
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