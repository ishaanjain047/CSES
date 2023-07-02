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
vector<ll> parent(100001, -1);
vector<ll> rankVertex(100001, -1);
vector<vector<ll>> edges;
void unionVertex(ll u, ll v)
{
    u = parent[u];
    v = parent[v];
    // ultimate parents hai yeh
    if (rankVertex[u] < rankVertex[v])
    {
        parent[u] = v;
    }
    else if (rankVertex[v] < rankVertex[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rankVertex[v]++;
    }
}
ll findpar(ll node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findpar(parent[node]);
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        vector<ll> temp;
        temp.pb(wt);
        temp.pb(u);
        temp.pb(v);
        edges.pb(temp);
    }
    sort(edges.begin(), edges.end());
    for (ll i = 0; i <= n; i++)
    {
        parent[i] = i;
        rankVertex[i] = 0;
    }
    ll ans = 0;
    ll cnt = 0;
    for (ll i = 0; i < m; i++)
    {
        ll u = edges[i][1];
        ll v = edges[i][2];
        ll wt = edges[i][0];
        if (findpar(u) == findpar(v))
            continue;
        else
        {
            cnt++;
            ans += wt;
            unionVertex(u, v);
        }
    }
    (cnt == n - 1) ? cout << ans << endl : cout << "IMPOSSIBLE" << endl;
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