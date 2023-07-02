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
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    vector<ll> dist(n + 1, 0);
    dist[1] = 0;
    vector<ll> parent(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        // we will relax edges n-1 times
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }
    int flag = 0;
    ll y;
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] + wt < dist[v])
        {
            y = u;
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        for (int i = 1; i <= n; i++)
        {
            y = parent[y];
        }
        vector<ll> path;
        ll currnode = y;
        while (parent[currnode] != y)
        {
            path.pb(currnode);
            currnode = parent[currnode];
        }
        path.pb(currnode);
        path.pb(y);
        cout << "YES" << endl;
        reverse(path.begin(), path.end());
        for (auto &it : path)
        {

            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
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