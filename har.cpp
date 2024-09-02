#include <bits/stdc++.h>
using namespace std;
long getMin(vector<int> center, vector<int> destionation)
{
    int n = center.size();
    sort(center.begin(), center.end());
    sort(destionation.begin(), destionation.end());
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(center[i] - destionation[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    cout << getMin(v1, v2);
}