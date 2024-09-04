#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
}
signed main()
{
    vector<int> v = {4, 8, 15, 16, 23, 42};
    vector<int> ans;
    vector<int> num;
    for (int i = 0; i < 2; i++)
    {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        int x;
        cin >> x;
        int f = 0;
        for (int j = 0; j < 6; j++)
        {
            for (int k = j + 1; k < 6; k++)
            {
                if ((v[j] * v[k]) == x && num.size())
                {
                    f = 1;
                    if (num.size() && num[0] == v[j])
                    {
                        ans.push_back(num[1]);
                        ans.push_back(num[0]);
                        ans.push_back(v[k]);
                    }
                    else if (num.size() && num[0] == v[k])
                    {
                        ans.push_back(num[1]);
                        ans.push_back(num[0]);
                        ans.push_back(v[j]);
                    }
                    else if (num.size() && num[1] == v[k])
                    {
                        ans.push_back(num[0]);
                        ans.push_back(num[1]);
                        ans.push_back(v[j]);
                    }
                    else
                    {
                        ans.push_back(num[0]);
                        ans.push_back(num[1]);
                        ans.push_back(v[k]);
                    }
                    num.push_back(v[j]);
                    num.push_back(v[k]);
                    break;
                }
                else if ((v[j] * v[k]) == x)
                {
                    num.push_back(v[j]);
                    num.push_back(v[k]);
                }
            }
            if (f == 1)
                break;
        }
    }
    vector<int> ans1 = ans;
    ans.clear();
    num.clear();
    for (int i = 3; i < 5; i++)
    {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        int x;
        cin >> x;
        int f = 0;
        for (int j = 0; j < 6; j++)
        {
            for (int k = j + 1; k < 6; k++)
            {
                if ((v[j] * v[k]) == x && num.size())
                {
                    f = 1;
                    if (num.size() && num[0] == v[j])
                    {
                        ans.push_back(num[1]);
                        ans.push_back(num[0]);
                        ans.push_back(v[k]);
                    }
                    else if (num.size() && num[0] == v[k])
                    {
                        ans.push_back(num[1]);
                        ans.push_back(num[0]);
                        ans.push_back(v[j]);
                    }
                    else if (num.size() && num[1] == v[k])
                    {
                        ans.push_back(num[0]);
                        ans.push_back(num[1]);
                        ans.push_back(v[j]);
                    }
                    else
                    {
                        ans.push_back(num[0]);
                        ans.push_back(num[1]);
                        ans.push_back(v[k]);
                    }
                    num.push_back(v[j]);
                    num.push_back(v[k]);
                    break;
                }
                else if ((v[j] * v[k]) == x)
                {
                    num.push_back(v[j]);
                    num.push_back(v[k]);
                }
            }
            if (f == 1)
                break;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        ans1.push_back(ans[i]);
    }
    cout << "! ";
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    fflush(stdout);
}