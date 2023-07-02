#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;
const int INF = 1e9;

vector<pair<ll, ll>> adj[MAXN];
ll dp[MAXN][2];

ll dfs(ll node, ll coupon_used, vector<pair<ll, ll>> adj[])
{
    if (node == 1) // Base case: Reached Syrjälä
        return 0;

    if (dp[node][coupon_used] != -1) // Check if already calculated
        return dp[node][coupon_used];

    ll min_cost = INF;

    for (auto &it : adj[node])
    {
        ll neighbor = it.first;
        ll price = it.second;
        ll new_coupon_used = coupon_used;
        if (coupon_used == 0 && price % 2 == 0) // Check if price can be halved
            new_coupon_used = 1;

        ll cost = price / (1 << coupon_used) + dfs(neighbor, new_coupon_used, adj);
        min_cost = min(min_cost, cost);
    }

    dp[node][coupon_used] = min_cost; // Store the calculated minimum cost
    return min_cost;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    memset(dp, -1, sizeof(dp)); // Initialize dp array with -1

    ll result = dfs(n, 0, adj); // Call dfs from Metsälä (n) without using the coupon

    cout << result << endl;

    return 0;
}
