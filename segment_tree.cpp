#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int Arr[N], seg[4 * N];
void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = Arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int query(int ind, int low, int high, int l, int h)
{
    if (l <= low && h >= high)
    {
        return seg[ind];
    }
    if (low > h || high < l)
        return -1e8;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, h);
    int right = query(2 * ind + 2, mid + 1, high, l, h);
    return max(left, right);
}
int main()
{
}