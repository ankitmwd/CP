#include <bits/stdc++.h>
using namespace std;
#define int long long int
int fun(vector<int> &v, int cnt)
{
    int sum = 0;
    priority_queue<int> pq;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 0)
        {
            sum += v[i];
            cnt--;
        }
        else
        {
            int y = abs(v[i]);
            if (!pq.empty())
            {
                if (sum >= y)
                {
                    sum -= y;
                    pq.push(y);
                    cnt--;
                }
                else
                {
                    if (pq.top() > y)
                    {
                        sum += pq.top();
                        sum -= y;
                        pq.pop();
                        pq.push(y);
                    }
                }
            }
            else
            {
                if (sum >= y)
                {
                    sum -= y;
                    pq.push(y);
                    cnt--;
                }
            }
        }
    }
    if(cnt<=0) return true;
    else return false;
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
    int l = 0;
    int h = n;
    int ans = 0;
    while (h >= l)
    {
        int mid = (h + l) / 2;
        if (fun(v, mid) == 1)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << ans << endl;
}
signed main()
{

    solve();
}