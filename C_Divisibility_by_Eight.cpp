#include <bits/stdc++.h>
using namespace std;
#define int long long int
void fun(int i, int &ans, vector<int> temp, string &str)
{
    int n = str.size();
    if (temp.size() > 3)
        return;
    if (temp.size() == 3)
    {
        int num = temp[0] * 100 + temp[1] * 10 + temp[2];
        // cout << num << endl;
        if (num % 8 == 0)
        {
            ans = num;
        }
        return;
    }
    if (i >= n)
        return;
    temp.push_back(str[i] - '0');
    fun(i + 1, ans, temp, str);
    temp.pop_back();
    fun(i + 1, ans, temp, str);
}
void fun1(int i, int &ans, vector<int> temp, string &str)
{
    int n = str.size();

    if (temp.size() > 2)
        return;
    if (temp.size() == 2)
    {
        int num = temp[0] * 10 + temp[1];
        // cout << num << endl;
        if (num % 8 == 0)
        {
            ans = num;
        }
        return;
    }
    if (i >= n)
        return;

    temp.push_back(str[i] - '0');
    fun1(i + 1, ans, temp, str);
    temp.pop_back();
    fun1(i + 1, ans, temp, str);
}
void solve()
{
    string str;
    cin >> str;
    vector<int> temp;
    int ans = -1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0' || str[i] == '8')
        {
            cout<<"YES"<<endl;
            cout << str[i] << endl;
            return;
        }
    }
    fun1(0, ans, temp, str);
    if (ans != -1)
    {
        cout << "YES" << endl;
        cout << ans << endl;
        return;
    }
    fun(0, ans, temp, str);
    if (ans != -1)
    {
        cout << "YES" << endl;
        cout << ans << endl;
        return;
    }
    cout << "NO" << endl;
}
signed main()
{

    solve();
}