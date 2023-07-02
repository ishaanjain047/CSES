#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int par, vector<int> &vis, vector<int> &pathvis, vector<int> &parent, vector<int> adj[], int &sv, int &ev)
{
    vis[node] = 1;
    pathvis[node] = 1;
    parent[node] = par;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, node, vis, pathvis, parent, adj, sv, ev))
                return true;
        }
        else
        {
            // if (child == par)
            //     continue;
            if (pathvis[child] && vis[child])
            {
                sv = child;
                ev = node;
                return true;
            }
        }
    }
    pathvis[node] = 0;
    return false;
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
    }
    vector<int> vis(n + 1, 0);
    vector<int> pathvis(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int flag = 0;
    int sv, ev;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, pathvis, parent, adj, sv, ev))
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int currnode = ev;
        vector<int> ans;
        while (parent[currnode] != sv)
        {
            ans.push_back(currnode);
            currnode = parent[currnode];
        }
        ans.push_back(currnode);
        ans.push_back(sv);
        // jab currnode ka parent sv hai, toh break ho gya, now tu currnode par pahuch fir sv par
        reverse(ans.begin(), ans.end());
        ans.push_back(sv);
        // yeh isliye coz you started from here, yeh daala hi nhi tha humne
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}