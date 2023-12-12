#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;

    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxJump = __lg(n) + 1;

    vi depth(n), pre(n), post(n);
    vvi jmp(maxJump, vi(n, -1));

    int t = 0;
    auto dfs = [&](int cur, int prv, auto &dfs) -> void {
        pre[cur] = t++;
        jmp[0][cur] = prv;
        for(int nxt: adj[cur]) if(nxt != prv) {
            depth[nxt] = depth[cur] + 1;
            dfs(nxt, cur, dfs);
        }
        post[cur] = t++;
    };
    dfs(0, -1, dfs);

    rep(i, 1, maxJump) {
        rep(j, 0, n) {
            int prv = jmp[i-1][j];
            if(prv == -1) continue;
            jmp[i][j] = jmp[i-1][prv];
        }
    }

    auto lift = [&](int x, int k) {
        rep(i, 0, maxJump)
            if(x != -1 && (k >> i) & 1)
                x = jmp[i][x];
        return x;
    };

    auto lca = [&](int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if(u == v) return u;
        for(int i = maxJump-1; i >= 0; i--)
            if(jmp[i][u] != jmp[i][v])
                u = jmp[i][u], v = jmp[i][v];
        return jmp[0][u];
    };

    vi euler(2*n + 1);
    vi lcaFreq(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        int l = lca(u, v);
        lcaFreq[l]++;
        euler[pre[l]] += 2;
        euler[pre[u]+1] -= 1;
        euler[pre[v]+1] -= 1;
    }

    partial_sum(all(euler), begin(euler));

    rep(i, 0, n)
        cout << euler[pre[i]] - euler[post[i]] - lcaFreq[i] << ' ';
    cout << '\n';

    return 0;
}