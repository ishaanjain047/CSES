#include <bits/stdc++.h>
using namespace std;
void bfs(int node, int &n, vector<int> &dist, vector<int> &parent, vector<int> adj[])
{
    queue<pair<int, int>> q;
    dist[1] = 0;
    q.push({1, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        parent[node] = par;
        q.pop();
        for (auto child : adj[node])
        {
            if (dist[node] + 1 < dist[child])
            {
                dist[child] = dist[node] + 1;
                q.push({child, node});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1, -1);
    bfs(1, n, dist, parent, adj);
    if (parent[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int currnode = n;
        vector<int> path;
        while (parent[currnode] != 1)
        {
            path.push_back(currnode);
            currnode = parent[currnode];
        }
        path.push_back(currnode);
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (auto &it : path)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}