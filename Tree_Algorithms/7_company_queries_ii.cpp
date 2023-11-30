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

    int n, q; cin >> n >> q;

    int maxJump = __lg(n) + 1;
    vvi jmp(maxJump, vi(n, -1));
    vvi adj(n);
    rep(i, 1, n) {
        cin >> jmp[0][i], jmp[0][i]--;
        adj[jmp[0][i]].push_back(i);
    }

    vi depth(n);
    auto getDepths = [&](int cur, auto &getDepths) -> void {
        for(int nxt: adj[cur]) {
            depth[nxt] = depth[cur] + 1;
            getDepths(nxt, getDepths);
        }
    };
    getDepths(0, getDepths);

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

    rep(i, 0, q) {
        int u, v; cin >> u >> v; u--, v--;
        cout << lca(u, v) + 1 << '\n';
    }

    return 0;
}