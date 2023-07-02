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

ll dfs(int node, int n, vector<ll> &vis, vector<ll> &parent, vector<ll> &dp, vector<ll> adj[])
{
    if (node == n)
        return 0;
    if (dp[node] != -1)
        return dp[node];
    ll ans = LLONG_MIN;
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            ll x = dfs(child, n, vis, parent, dp, adj);
            ll travelcost = (x == LLONG_MIN) ? LLONG_MIN : 1 + x;
            if (travelcost >= ans)
            {
                parent[child] = node;
                ans = travelcost;
            }
        }
        ll costbychild = 1 + dp[child];
        if (costbychild >= ans)
        {
            parent[child] = node;
            ans = costbychild;
        }
    }
    // vis[node] = 0;
    return dp[node] = ans;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1];
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    vector<ll> vis(n + 1, 0);
    vector<ll> dp(n + 1, -1);
    vector<ll> parent(n + 1, 0);
    ll dist = dfs(1, n, vis, parent, dp, adj);
    vector<ll> path;
    ll currnode = n;
    while (parent[currnode] != 0)
    {
        path.pb(currnode);
        currnode = parent[currnode];
    }
    path.pb(1);
    if (path.size() == 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (ll i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}