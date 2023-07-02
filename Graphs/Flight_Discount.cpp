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
ll dfs(ll node, ll state, ll n, vector<pair<ll, ll>> adj[], vector<vector<ll>> &dp, vector<ll> &vis)
{
    if (node == n)
        return 0;
    if (dp[node][state] != -1)
        return dp[node][state];
    ll ans = LLONG_MAX;
    // vis[node] = 1;
    for (auto it : adj[node])
    {
        ll child = it.first;
        ll wt = it.second;
        // if (!vis[child])
        // {
        if (state == 1)
        {
            ll x = dfs(child, 1, n, adj, dp, vis);
            ll nodisc = (x == LLONG_MAX) ? LLONG_MAX : wt + x;
            ll y = dfs(child, 0, n, adj, dp, vis);
            ll disc = (y == LLONG_MAX) ? LLONG_MAX : (wt / 2 + y);
            ans = min(ans, min(disc, nodisc));
        }
        else
        {
            ll x = dfs(child, 0, n, adj, dp, vis);
            ll nodisc = (x == LLONG_MAX) ? LLONG_MAX : wt + x;
            ans = min(ans, nodisc);
        }
        // }
    }
    // vis[node] = 0;
    return dp[node][state] = ans;
    // agar kisi dfs call ka kuch nhi chala toh voh yeh degi
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj[n + 1];
    for (ll i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
    vector<ll> vis(n + 1, 0);
    cout << dfs(1, 1, n, adj, dp, vis) << endl;
}
int main()
{
    Code By Jaini
        ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}