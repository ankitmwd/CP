#include <bits/stdc++.h>
using namespace std;
void fun(int rw, int cl, vector<string> &v, vector<vector<int>> &vis)
{
    vis[rw][cl] = 1;
    int n = v.size();
    int m = v[0].size();
    int r[] = {1, -1, 0, 0};
    int c[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++)
    {
        int nr = rw + r[i];
        int nc = cl + c[i];
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0 && v[nr][nc] == '.')
        {
            
            fun(nr, nc, v, vis);
        }
    }
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.' && vis[i][j] == 0)
            {
                ans++;
                fun(i, j, v, vis);
            }
        }
    }
    cout << ans << endl;
    return 0;
}