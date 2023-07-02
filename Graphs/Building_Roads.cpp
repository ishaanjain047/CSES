#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &visited, vector<int> adj[])
{
    visited[node] = 1;
    for (auto child : adj[node])
    {
        if (!visited[child])
            dfs(child, visited, adj);
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
    vector<int> visited(n + 1, 0);
    int cnt = 0;
    vector<pair<int, int>> roads;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (i == 1)
            {
                dfs(i, visited, adj);
                continue;
            }
            else
            {
                cnt++;
                roads.push_back({1, i});
                dfs(i, visited, adj);
            }
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < roads.size(); i++)
    {
        cout << roads[i].first << " " << roads[i].second << endl;
    }
}