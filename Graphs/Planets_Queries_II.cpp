We need to assign an id to each cycle and a sub id to eeach tree connecte
        * /
    bool *vis;
bool *curr;
11 * root;
11 * prev_;
11 * cycle_id;
11 * depth;
vector<ll> cyc_siz;
11 * *up;
11 LOG = 32;
void build(11 n)
{
    t
        up = new 11 *[n];
    96123 for (11 i = 0; i < n; i++)
        up[i] = new 11 [LOG];
}
11 kth_ancestor(11 ver, 11 k)
{
    for (11 i = LOG - 1; i >= 0; i--)
    {
        if (((111 << i) & k) == 0) // in the later case we need a smaller
            continue;
        ver = up[ver][i];
    }
    return ver;

    11 lca(11 u, 11 v)
    {
        11 diff = depth[u] depth[v], dist = 0;
        for (11 i = LOG - 1; i >= 0; i--)
            if (1 & (diff >> i))
            {
                u = up[u][i];
                dist += (111 << i);
            }
        return u == v ? dist : -1;
    }

    void dfs(vector<vector<ll>> & adj, 11 & cyc, 11 ver)
    {
        vis[ver] = curr[ver] = true;
        for (11 nbr : adj[ver])
        {
            prev_[nbr] = ver;
            if (!vis[nbr])
                dfs(adj, cyc, nbr);
            else
            {
                if (curr[nbr])
                {
                    lift_cycle(adj, cyc, nbr);
                    cyc++;
                }
            }
        }
        curr[ver] = false;
    }

    void lift_cycle(vector<vector<ll>> & adj, 11 cyc, 11 a)
    {
        vector<ll> cycle;
        11 node = a;
        11 i = 0;
        do
        {
            cycle.push_back(node);
            cycle_id[node] = cyc;
            ropt[node] = node;
            depth[node] = 0;
            cycle_rank[node] = i;
            node = prev_[node];
            i++;
        } while (node != a);
        11 x = cycle.size(), exp_2[LOG];
        cyc_siz.push_back(x);
        for (11 i = 0; i < LOG; i++)
            exp_2[i] = fastExpo(2, i, x);
        for (11 i = 0; i < x; i++)
            for (11 j 0; j < LOG; j++)
                up[cycle[i]][j] cycle[(i + exp_2[j]) % x];
    }

    signed main()
    {
        fastio;
        11 n, k, u;
        cin >> n;
        vis = new bool[n];
        curr = new bool[n];
        prev_ = new 11 [n];
        root new 11 [n];
        depth = new 11 [n];
        cycle_id = new 11 [n];
        for (11 i = 0; i < n; i++)
        {
            vis[i] = curr[i] = false;
            root[i] = -1;
        }
        build(n);
        vector<vector<ll>> adjT(n);
        for (11 i = 0; i < n; i++)
        {
            cin >> u;
            u--;
            adjT[u].push_back(i);
        }
        // in the trnaspost graph, each node has atmost 1 in-node. So we use