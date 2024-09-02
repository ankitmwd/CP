#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v1, v2, v3;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v1.push_back(v[i]);
        v2.push_back(v[i]);
        v3.push_back(v[i]);
    }
    int sign = 1;
    int ind = 0;
    for (int i = 0; i < v.size() - 2; i++)
    {
        if (__gcd(v[i], v[i + 1]) > __gcd(v[i + 1], v[i + 2]))
        {
            ind = i;
            // cout << "ind : " << ind << endl;
            sign = 0;
            break;
        }
    }
    if (sign)
    {
        cout << "YES" << endl;
        return;
    }
    v1.erase(v1.begin() + ind);
    v2.erase(v2.begin() + ind + 1);
    v3.erase(v3.begin() + ind + 2);
    sign = 1;
    for (int i = 0; i < v1.size() - 2; i++)
    {

        if (__gcd(v1[i], v1[i + 1]) > __gcd(v1[i + 1], v1[i + 2]))
        {
            sign = 0;
            break;
        }
    }
    if (sign)
    {
        cout << "YES" << endl;
        return;
    }
    sign = 1;

    for (int i = 0; i < v2.size() - 2; i++)
    {
        if (__gcd(v2[i], v2[i + 1]) > __gcd(v2[i + 1], v2[i + 2]))
        {
            sign = 0;
            break;
        }
    }
    if (sign)
    {
        cout << "YES" << endl;
        return;
    }
    sign = 1;
    for (int i = 0; i < v3.size() - 2; i++)
    {
        if (__gcd(v3[i], v3[i + 1]) > __gcd(v3[i + 1], v3[i + 2]))
        {
            sign = 0;
            break;
        }
    }
    if (sign)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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