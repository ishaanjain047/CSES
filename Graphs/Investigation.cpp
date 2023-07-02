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
typedef pair<pll, ll> pp;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Jaini cout.tie(NULL);
ll M = 1000000007;
set<ll> parents[100001];
// parent is also a list of vectors now
vector<pll> adj[100001];
vector<ll> dist(100001);
vector<ll> dp(100001);
vector<pll> numflights(100001);
ll add(ll a, ll b)
{
    return ((a % M) + (b % M)) % M;
}
void djiktra(ll n)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({{0, 1}, -1});
    dist[1] = 0;
    while (!pq.empty())
    {
        pll p = pq.top().first;
        ll par = pq.top().second;
        ll node = p.second;
        ll distance = p.first;
        pq.pop();
        if (distance > dist[node])
            continue;
        parents[node].insert(par);
        // isko neeche nhi update kar skte
        for (auto it : adj[node])
        {
            ll child = it.first;
            ll wt = it.second;
            if (dist[node] + wt <= dist[child])
            {
                dist[child] = dist[node] + wt;
                // parents[child].insert(node);
                pq.push({{dist[child], child}, node});
            }
        }
    }
}
pll flights(ll node)
{
    if (node == 1)
    {
        return {0, 0};
    }
    pll p = {-1, -1};
    if (numflights[node] != p)
    {
        return numflights[node];
    }
    ll minf = LLONG_MAX;
    ll maxf = LLONG_MIN;
    for (auto child : parents[node])
    {
        minf = min(minf, 1 + flights(child).first);
        maxf = max(maxf, 1 + flights(child).second);
    }
    return numflights[node] = {minf, maxf};
}
ll calcways(ll node)
{
    if (node == 1)
    {
        return 1;
    }
    if (dp[node] != -1)
    {
        return dp[node];
    }
    ll ways = 0;
    for (auto child : parents[node])
    {
        ways = add(ways, calcways(child));
    }
    return dp[node] = ways;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
    }
    for (int i = 0; i <= 100000; i++)
    {
        dist[i] = LLONG_MAX;
        dp[i] = -1;
        numflights[i] = {-1, -1};
    }
    djiktra(n);
    cout << dist[n] << " " << calcways(n) << " " << flights(n).first << " " << flights(n).second << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "vertex " << i << " parents are ";
    //     for (auto it : parents[i])
    //     {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << minflights[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << maxflights[i] << " ";
    // }
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