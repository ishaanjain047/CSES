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
    ll n, q;
    cin >> n >> q;
    int maxN = log2(1e9);
    // isse maxN 29 aaya, toh for safe side I made of 30
    int LCA[n + 1][30];
    memset(LCA, -1, sizeof(LCA));
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        LCA[i][0] = x;
    }
    for (int j = 1; j <= 29; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            ll par = LCA[i][j - 1];
            if (par != -1)
            {
                LCA[i][j] = LCA[par][j - 1];
            }
        }
    }
    for (ll i = 0; i < q; i++)
    {
        ll v, k;
        cin >> v >> k;
        while (k > 0)
        {
            ll i = log2(k);
            v = LCA[v][i];
            k -= (1 << i);
        }
        cout << v << endl;
    }
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}