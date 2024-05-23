#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int fun(int start, int end, unordered_map<int, vector<int>> &Adj, int n)
{
    unordered_set<int> vis;
    queue<pair<int, int>> que;
    que.push({start, 0});
    while (!que.empty())
    {
        int Node = que.front().first;
        int step = que.front().second;
        vis.insert(Node);
        if (Node == end)
            return step;
        que.pop();
        for (auto child : Adj[Node])
        {
            if (vis.find(child)==vis.end())
            {
                vis.insert(child);
                que.push({child, step + 1});
            }
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> Adj;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    cin >> x >> y;
    int ans = fun(x, y, Adj, n);
    cout << (ans == -1 ? 0 : ans) << endl;
}
