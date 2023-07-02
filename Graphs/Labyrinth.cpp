#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
bool check(ll r, ll c, vector<vector<ll>> &v)
{
    ll n = v.size();
    ll m = v[0].size();
    if (r >= 0 && r <= n - 1 && c >= 0 && c <= m - 1 && v[r][c] != -1)
    {
        return true;
    }
    return false;
}
vector<pair<ll, ll>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(ll sx, ll sy, ll ex, ll ey, vector<vector<ll>> &vis, vector<vector<pll>> &parent, vector<vector<ll>> &v)
{
    queue<pair<pll, pll>> q;
    q.push({{sx, sy}, {-1, -1}});
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        pll cell = q.front().first;
        pll par = q.front().second;
        ll x = cell.first;
        ll y = cell.second;
        parent[x][y] = par;
        q.pop();
        if (v[x][y] == 2)
        {
            return;
            // coz agar yeh mila in bfs, means shortest path se hi mila hoga
        }
        for (ll i = 0; i < moves.size(); i++)
        {
            ll newx = x + moves[i].first;
            ll newy = y + moves[i].second;
            if (check(newx, newy, v) && vis[newx][newy] == 0)
            {
                vis[newx][newy] = 1;
                q.push({{newx, newy}, {x, y}});
            }
        }
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    ll sx, sy, ex, ey;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (ll j = 0; j < m; j++)
        {
            char ch = s[j];
            if (ch == 'A')
            {
                v[i][j] = 1;
                sx = i;
                sy = j;
            }
            else if (ch == 'B')
            {
                v[i][j] = 2;
                ex = i;
                ey = j;
            }
            else if (ch == '.')
            {
                v[i][j] = 0;
            }
            else
            {
                v[i][j] = -1;
            }
        }
    }
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    vector<vector<pll>> parent(n, vector<pll>(m, {-1, -1}));
    // har ek cell mein -1,-1 hai
    bfs(sx, sy, ex, ey, vis, parent, v);
    pll neg = {-1, -1};
    if (parent[ex][ey] == neg)
    {
        cout << "NO" << endl;
    }
    else
    {
        string ans = "";
        ll currx = ex;
        ll curry = ey;
        while (parent[currx][curry] != neg)
        {
            ll parx = parent[currx][curry].first;
            ll pary = parent[currx][curry].second;
            if (parx == currx + 1)
            {
                ans += 'U';
            }
            else if (parx == currx - 1)
            {
                ans += 'D';
            }
            else if (pary == curry - 1)
            {
                ans += 'R';
            }
            else
            {
                ans += 'L';
            }
            currx = parx;
            curry = pary;
        }
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }
}
