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

    int n; cin >> n;
    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi depth(n);
    auto dfs = [&](int cur, int prv, auto &dfs) -> void {
        for(int nxt: adj[cur]) if(nxt != prv) {
            depth[nxt] = depth[cur] + 1;
            dfs(nxt, cur, dfs);
        }
    };

    dfs(0, -1, dfs);

    int maxDepth = -1, idx = -1;
    rep(i, 0, n)
        if(depth[i] > maxDepth)
            maxDepth = depth[i], idx = i;
    
    depth[idx] = 0;
    dfs(idx, -1, dfs);

    cout << *max_element(all(depth)) << '\n';

    return 0;
}