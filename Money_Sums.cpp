#include <bits/stdc++.h>
using namespace std;
// #define int long long int
void fun(int ind, int sum, vector<int> &v, set<int> &st)
{
    int n = v.size();
    if (ind >= n)
    {
        st.insert(sum);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        fun(i + 1, sum + v[i], v, st);
        fun(i + 1, sum, v, st);
    }
    return;
}
signed main()
{
    int n;
    cin >> n;
    set<int> st;
    vector<int> v(n);
    // int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // mx += v[i];
    }
    fun(0, 0, v, st);
    st.erase(0);
    cout << st.size() << endl;
    for (auto x : st)
    {
        cout << x << " ";
    }
}