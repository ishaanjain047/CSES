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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> matrix(n + 1, vector<ll>(n + 1, LLONG_MAX));
    for (ll i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        // question doesnt say single road, there can be multiple roads
        if (matrix[u][v] > wt)
        {
            matrix[u][v] = wt;
        }
        if (matrix[v][u] > wt)
        {
            matrix[v][u] = wt;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // This is missed in step 1
        matrix[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][k] == LLONG_MAX || matrix[k][j] == LLONG_MAX)
                {
                    continue;
                }
                matrix[i][j] = min(matrix[i][j],
                                   matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == LLONG_MAX)
            {
                matrix[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << matrix[u][v] << endl;
    }
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}