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
ll M = 1000000007;
ll add(ll a, ll b)
{
    return ((a % M) + (b % M)) % M;
}
int dfs(int node, int n, vector<ll> &vis, vector<ll> &dp, vector<ll> adj[])
{
    if (node == n)
        return 1;
    if (dp[node] != -1)
        return dp[node];
    vis[node] = 1;
    ll ans = 0;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            int x = dfs(child, n, vis, dp, adj);
        }
        if (dp[child] != -1)
        {
            ans = add(ans, dp[child]);
        }
    }
    vis[node] = 0;
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
    cout << dfs(1, n, vis, dp, adj) << endl;
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}