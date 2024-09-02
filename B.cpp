#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int n;
    cin >> n;
    vector<int> pods(n), cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pods[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[pods[i]].push_back(cost[i]);
    }
    auto it = mp.begin();
    it++;
    int sum = 0;
    for (auto x : mp)
    {
        auto Arr = x.second;
        sort(Arr.begin(), Arr.end());
        Arr.pop_back();
        if (it->first > x.first + Arr.size())
        {
            int sz = Arr.size();
            for (int i = 0; i < sz; i++)
            {
                sum += (sz - i) * Arr[i];
            }
        }
        else
        {
            int sz = (it->first - x.first - 1);
            int sz1 = Arr.size();
            sz1--;
            for (int i = 0; i < (it->first - x.first - 1); i++)
            {
                sum += (i + 1) * Arr[sz1];
                sz1--;
                Arr.pop_back();
            }
            for (auto x1 : Arr)
            {
                sum += (sz + 1) * x1;
                mp[it->first].push_back(x1);
            }
        }
        it++;
        // cout << sum << endl;
        if (it == mp.end())
        {
            it--;
            break;
        }
    }
    sort(mp[it->first].begin(), mp[it->first].end());
    mp[it->first].pop_back();
    int sz = mp[it->first].size();
    for (auto x : mp[it->first])
    {
        sum += (sz)*x;
        sz--;
    }
    cout << sum << endl;
}
