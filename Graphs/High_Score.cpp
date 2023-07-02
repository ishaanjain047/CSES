#include <bits/stdc++.h>
typedef long long ll;
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff first
#define ss second
#define pb push_back
#define mpair make_pair
using namespace std;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef map<ll, ll> mp;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Jaini cout.tie(NULL);
void dfs(int node, vector<ll> &vis, vector<ll> adj[])
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, vis, adj);
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    vector<ll> forward[n + 1];
    vector<ll> backward[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        forward[u].push_back(v);
        backward[v].push_back(u);
        edges.push_back({u, v, -1 * wt});
    }
    vector<ll> visf(n + 1, 0);
    vector<ll> visb(n + 1, 0);
    dfs(1, visf, forward);
    dfs(n, visb, backward);
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // we will relax edges n-1 times
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] == LLONG_MAX)
                continue;
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    int flag = 0;
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] == LLONG_MIN)
            continue;
        if (dist[u] + wt < dist[v])
        {
            if (visf[u] == 1 && visb[u] == 1)
            {
                flag = 1;
            }
        }
    }
    if (flag)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << -dist[n] << endl;
    }
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}