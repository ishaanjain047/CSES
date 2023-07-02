#include <bits/stdc++.h>
typedef long long ll;
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff first
#define ss second
#define pb push_back
#define mpair make_pair
using namespace std;
typedef pair<ll, ll> pi;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Jaini cout.tie(NULL);
vector<pair<ll, ll>> adj[100001];
vector<ll> dist(100001, LLONG_MAX);
vector<ll> vis(100001, 0);
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    dist[1] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll currdist = pq.top().first;
        ll currnode = pq.top().second;
        pq.pop();
        if (currdist > dist[currnode])
            continue;
        for (auto child : adj[currnode])
        {
            ll adjNode = child.first;
            ll wt = child.second;
            if (dist[currnode] != LLONG_MAX)
            {
                if (dist[currnode] + wt < dist[adjNode])
                {
                    dist[adjNode] = dist[currnode] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}