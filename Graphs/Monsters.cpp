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
bool check(int r, int c, vector<string> &v)
{
    int n = v.size();
    int m = v[0].size();
    if (r >= 0 && c >= 0 && r <= n - 1 && c <= m - 1 && v[r][c] != '#')
    {
        return true;
    }
    return false;
}

vector<pair<ll, ll>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<ll>> distA(1001, vector<ll>(1001, LLONG_MAX));
void bfsA(ll sx, ll sy, vector<vector<pll>> &parent, vector<string> &A, vector<vector<ll>> &vis)
{
    queue<pair<pll, pll>> q;
    q.push({{sx, sy}, {-1, -1}});
    vis[sx][sy] = 1;
    distA[sx][sy] = 0;
    while (!q.empty())
    {
        pll cell = q.front().first;
        pll par = q.front().second;
        ll x = cell.first;
        ll y = cell.second;
        parent[x][y] = par;
        q.pop();
        for (ll i = 0; i < moves.size(); i++)
        {
            ll newx = x + moves[i].first;
            ll newy = y + moves[i].second;
            if (check(newx, newy, A) && vis[newx][newy] == 0)
            {
                vis[newx][newy] = 1;
                distA[newx][newy] = 1 + distA[x][y];
                q.push({{newx, newy}, {x, y}});
            }
        }
    }
}

void bfsM(vector<string> &v, vector<vector<ll>> &vis)
{
    queue<pll> q;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if ()
    //     }
    // }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    vector<vector<ll>> visA(n, vector<ll>(m, 0));
    vector<vector<pll>> parent(n, vector<pll>(m, {-1, -1}));
    map<pair<ll, ll>, ll> mp;
    ll sx, sy;
    // ab agar ek jagah par monster hai, toh voh position is -1 for A, kyunki monster may not move
    bfsA(sx, sy, parent, v, visA);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << distA[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Code By Jaini
    solve();
    return 0;
}