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
void dfs1(ll node, vector<ll> adj[], vector<ll> &vis, stack<ll> &s)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dfs1(child, adj, vis, s);
        }
    }
    s.push(node);
}
void dfs2(ll node, vector<ll> adj[], vector<ll> &vis)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dfs2(child, adj, vis);
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adjf[n + 1];
    vector<ll> adjb[n + 1];
    vector<ll> vis(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adjf[u].pb(v);
        adjb[v].pb(u);
    }
    stack<ll> s;
    dfs1(1, adjf, vis, s);
    // agar pura graph connected nhi hai toh vaise hi nhi jaa skte
    for (ll i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return;
        }
    }
    // agar yaha pahucha it means the whole graph is already connected, now we need to check if its
    // strongly connected
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    ll scc = 0;
    ll first = -1;
    ll second = -1;

    // You cant traverse like this in a stack bsdk

    // for (auto it : s)
    // {
    //     ll node = *it;
    //     if (!vis[node])
    //     {
    //         scc++;
    //         if (scc == 1)
    //         {
    //             first = node;
    //         }
    //         if (scc == 2)
    //         {
    //             second = node;
    //         }
    //         dfs2(node, adjb, vis);
    //     }
    // }
    while (!s.empty())
    {
        ll node = s.top();
        s.pop();
        if (!vis[node])
        {
            scc++;
            if (scc == 1)
            {
                first = node;
            }
            if (scc == 2)
            {
                second = node;
            }
            dfs2(node, adjb, vis);
        }
    }
    if (scc == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        cout << second << " " << first << endl;
    }
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}