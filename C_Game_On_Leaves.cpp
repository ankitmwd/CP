#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, Node;
    cin >> n >> Node;
    vector<vector<int>> Adj(n + 1);
    vector<int> indegre(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
        indegre[x]++;
        indegre[y]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if (indegre[i] == 1)
        {
            que.push(i);
            indegre[i]--;
        }
    }
    int turn = 1;
    while (!que.empty())
    {
        vector<int> temp;
        while (!que.empty())
        {
            if (que.front() == Node)
            {
                if (turn)
                {
                    cout << "Ayush" << endl;
                }
                else
                {
                    cout << "Ashish" << endl;
                }
                return;
            }
            cout << que.front() << " ";
            temp.push_back(que.front());
            que.pop();
        }
        cout << endl;
        for (auto x : temp)
        {
            for (int y : Adj[x])
            {
                if (!(y == Node && indegre[y] == 2))
                {
                    indegre[y]--;
                }
                if (indegre[y] == 1)
                {
                    que.push(y);
                }
            }
        }
        turn = !turn;
    }
    if (turn)
    {
        cout << "Ayush" << endl;
    }
    else
    {
        cout << "Ashish" << endl;
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}