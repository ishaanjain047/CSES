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
ll givecolor(ll col)
{
    if (col == 1)
        return 2;
    else
        return 1;
}
bool distribute(ll i, vector<ll> &colors, vector<ll> adj[])
{
    queue<pair<ll, ll>> q;
    q.push({1, i});
    // color,node
    colors[i] = 1;
    ll flag = 1;
    while (!q.empty())
    {
        ll node = q.front().second;
        q.pop();
        for (auto child : adj[node])
        {
            if (colors[child] == -1)
            {
                colors[child] = givecolor(colors[node]);
                q.push({colors[child], child});
            }
            else
            {
                if (colors[child] == colors[node])
                {
                    flag = 0;
                    break;
                }
            }
        }
    }
    return flag;
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
        adj[v].pb(u);
    }
    vector<ll> colors(n + 1, -1);
    ll flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == -1)
        {
            if (distribute(i, colors, adj) == 0)
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
    {
        for (int i = 1; i <= n; i++)
            cout << colors[i] << " ";
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}