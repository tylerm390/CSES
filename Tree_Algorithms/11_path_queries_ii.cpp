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

struct SegTree {
    int n; vi st;
    SegTree(int n): n(n), st(n << 1) {}
    void update(int idx, int val) {
        st[idx += n] = val;
        while((idx >>= 1) != 0)
            st[idx] = max(st[2*idx], st[2*idx+1]);
    }
    int query(int L, int R) {
        L += n, R += n+1;
        int maxL = 0, maxR = 0;
        while(L < R) {
            if(L & 1) maxL = max(maxL, st[L++]);
            if(R & 1) maxR = max(maxR, st[--R]);
            L >>= 1, R >>= 1;
        }
        return max(maxL, maxR);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q; cin >> n >> q;

    vi vals(n);
    for(int &vi: vals) cin >> vi;

    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi depth(n), heavy(n, -1), par(n);
    auto dfs = [&](int cur, int prv, auto &dfs) -> int {
        int curSize = 1, bestSize = 0;
        for(int nxt: adj[cur]) if(nxt != prv) {
            depth[nxt] = depth[cur] + 1;
            par[nxt] = cur;
            int nxtSize = dfs(nxt, cur, dfs);
            curSize += nxtSize;
            if(nxtSize > bestSize)
                heavy[cur] = nxt, bestSize = nxtSize;
        }
        return curSize;
    };
    dfs(0, -1, dfs);

    vi head(n), idx(n);
    SegTree st(n);
    int t = 0;
    auto decompose = [&](int cur, int prv, int h, auto &decompose) -> void {
        head[cur] = h;
        idx[cur] = t;
        st.update(t++, vals[cur]);

        if(heavy[cur] != -1)
            decompose(heavy[cur], cur, h, decompose);
        
        for(int nxt: adj[cur])
            if(nxt != prv && nxt != heavy[cur])
                decompose(nxt, cur, nxt, decompose);
    };
    decompose(0, -1, 0, decompose);

    auto query = [&](int u, int v) -> int {
        int res = 0;
        while(head[u] != head[v]) {
            if(depth[head[u]] < depth[head[v]]) swap(u, v);
            res = max(res, st.query(idx[head[u]], idx[u]));
            u = par[head[u]];
        }
        if(depth[u] > depth[v]) swap(u, v);
        res = max(res, st.query(idx[u], idx[v]));
        return res;
    };

    auto update = [&](int u, int x) -> void {
        st.update(idx[u], x);
    };

    while(q--) {
        int type, x, y; cin >> type >> x >> y;
        if(type == 1) update(x-1, y);
        else cout << query(x-1, y-1) << ' ';
    }
    cout << '\n';

    return 0;
}