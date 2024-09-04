#include <bits/stdc++.h>
using namespace std;
#define int long long int
int bin(vector<int> &v, int aper, int bper, int a, int b, int cnt)
{
    int cm = (a * b) / __gcd(a, b);
    cm = cnt / cm;
    int k = 0;
    int sum = 0;
    int n = v.size();
    a = cnt / a;
    b = cnt / b;
    a = a - cm;
    b = b - cm;
    while (cm > 0 && k < n)
    {
        sum += (v[k]) * (aper + bper);
        k++;
        cm--;
    }
    if (aper < bper)
    {
        swap(bper, aper);
        swap(a, b);
    }
    while (a > 0)
    {
        sum += (v[k] * aper);
        k++;
        a--;
    }
    while (b > 0)
    {
        sum += (v[k] * bper);
        k++;
        b--;
    }
    // cout << sum << " " << cnt << endl;
    return sum / 100;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int aper, a, bper, b;
    cin >> aper >> a;
    cin >> bper >> b;
    int ans = -1;
    int l = 0;
    int h = n;
    int mn;
    cin >> mn;
    sort(v.rbegin(), v.rend());
    while (h >= l)
    {
        int mid = (l + h) / 2;
        if (bin(v, aper, bper, a, b, mid) >= mn)
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