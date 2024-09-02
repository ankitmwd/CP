#include <bits/stdc++.h>
using namespace std;
#define int long long int
int N = 1e4 + 10;
vector<bool> sign(N, 1);
vector<int> prime;
void solve1()
{
    sign[0] = 0;
    sign[1] = 0;
    for (int i = 2; i*i < N; i++)
    {
        if (sign[i] == 1)
        {
            for (int j = i * i; j < N; j += i)
            {
                sign[j] = 0;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int sz = prime.size();
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < sz; i++)
    {
        x = prime[i];
        for (int j = i + 1; j < sz; j++)
        {
            y = prime[j];
            z = n - (x + y);
            int ind = binary_search(prime.begin() + j + 1, prime.end(), z);
            if (ind)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}
signed main()
{
    int t;
    solve1();
    for (int i = 0; i < N; i++)
    {
        if (sign[i] ){
            prime.push_back(i * i);
            cout<<i<<endl;}
    }
    cout << prime.size() << endl;
    cin >> t;
    while (t--)
    {
        solve();
    }
}