#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define mpair make_pair
using namespace std;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef map<ll, ll> mp;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Vaish cout.tie(NULL);

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    vector<ll> dist(n + 1, 0);
    vector<ll> parent(n + 1);
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    priority_queue<pll> q;
    q.push({0, 1});
    dist[1] = 0;
    parent[1] = -1;
    while (!q.empty())
    {
        ll node = q.top().second;
        ll currdist = q.top().first;
        q.pop();
        if (dist[node] > currdist)
            continue;
        for (auto it : adj[node])
        {
            if (dist[it] < 1 + dist[node])
            {
                dist[it] = 1 + dist[node];
                parent[it] = node;
                q.push({dist[it], it});
            }
        }
    }

    if (dist[n] == 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        ll ct = n;
        vector<ll> ans;
        while (parent[ct] != -1)
        {
            ans.pb(ct);
            ct = parent[ct];
        }
        ans.pb(1);
        // reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (ll i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return;
}
int main()
{
    Code By Vaish
        ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}