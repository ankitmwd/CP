#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    string str;
    cin >> str;

    int reqB = 0, reqS = 0, reqC = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'B')
            reqB++;
        else if (str[i] == 'S')
            reqS++;
        else
            reqC++;
    }

    int HaveB, HaveS, HaveC;
    cin >> HaveB >> HaveS >> HaveC;
    int cstB, cstS, cstC;
    cin >> cstB >> cstS >> cstC;
    int mny;
    cin >> mny;
    int l = 0;
    int h = 1e15;
    int ans = 0;
    while (h >= l)
    {
        int mid = l + (h - l) / 2;
        int NeedB = mid * reqB - HaveB;
        int NeedS = mid * reqS - HaveS;
        int NeedC = mid * reqC - HaveC;
        if (NeedB <= 0)
        {
            NeedB = 0;
        }
        if (NeedS <= 0)
        {
            NeedS = 0;
        }
        if (NeedC <= 0)
        {
            NeedC = 0;
        }
        // cout << NeedB << " " << NeedS << " " << NeedC << endl;
        int tot_cost = NeedB * cstB + NeedS * cstS + NeedC * cstC;
        // cout << tot_cost << endl;
        if (tot_cost > mny)
        {
            h = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
signed main()
{

    solve();
}