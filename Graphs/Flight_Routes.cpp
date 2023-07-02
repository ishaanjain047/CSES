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
void djiktra(int k, int n, vector<vector<ll>> &dist, vector<pll> adj[])
{
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    // dist[1][k-1] = 0;
    dist[1][0] = 0;
    // yeh last vaala ko 0 thodna denge, fir kabhi 1st vertex ka last update hoga hi nhi
    pq.push({0, 1});
    // dist to node from 1, node
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll currdist = pq.top().first;
        pq.pop();
        if (currdist > dist[node][k - 1])
            continue;
        for (auto it : adj[node])
        {
            ll wt = it.second;
            ll child = it.first;
            if (dist[child][k - 1] > currdist + wt)
            {
                dist[child][k - 1] = currdist + wt;
                pq.push({dist[child][k - 1], child});
                sort(dist[child].begin(), dist[child].end());
            }
            else
            {
                continue;
            }
        }
    }
}
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pll> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, LLONG_MAX));
    djiktra(k, n, dist, adj);
    for (int i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}