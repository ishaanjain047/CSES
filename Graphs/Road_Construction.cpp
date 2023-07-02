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
vector<pll> rankVertex(100001);
vector<vector<ll>> edges;
void unionVertex(ll u, ll v, ll &maxsize)
{
    u = parent[u];
    v = parent[v];
    // ultimate parents hai yeh
    if (rankVertex[u].first < rankVertex[v].first)
    {
        parent[u] = v;
        rankVertex[v].second = rankVertex[u].second + rankVertex[v].second;
        if (rankVertex[v].second > maxsize)
        {
            maxsize = rankVertex[v].second;
        }
    }
    else if (rankVertex[v].first < rankVertex[u].first)
    {
        parent[v] = u;
        rankVertex[u].second = rankVertex[u].second + rankVertex[v].second;
        if (rankVertex[u].second > maxsize)
        {
            maxsize = rankVertex[u].second;
        }
    }
    else
    {
        parent[u] = v;
        rankVertex[v].first++;
        rankVertex[v].second = rankVertex[u].second + rankVertex[v].second;
        if (rankVertex[v].second > maxsize)
        {
            maxsize = rankVertex[v].second;
        }
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
        ll u, v;
        cin >> u >> v;
        vector<ll> temp;
        temp.pb(u);
        temp.pb(v);
        edges.pb(temp);
    }
    for (ll i = 0; i <= n; i++)
    {
        parent[i] = i;
        rankVertex[i].first = 0;
        rankVertex[i].second = 1;
    }
    ll currnum = n;
    ll maxsize = LLONG_MIN;
    for (ll i = 0; i < m; i++)
    {
        ll u = edges[i][0];
        ll v = edges[i][1];
        if (findpar(u) == findpar(v))
        {
            cout << currnum << " " << maxsize << endl;
        }
        else
        {
            currnum--;
            unionVertex(u, v, maxsize);
            cout << currnum << " " << maxsize << endl;
        }
    }
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