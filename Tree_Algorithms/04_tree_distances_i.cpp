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

    auto dfs = [&](int cur, int prv, vi &depth, auto &dfs) -> void {
        for(int nxt: adj[cur]) if(nxt != prv) {
            depth[nxt] = depth[cur] + 1;
            dfs(nxt, cur, depth, dfs);
        }
    };

    vi depth1(n);
    dfs(0, -1, depth1, dfs);

    int maxDepth = -1, idx1 = -1;
    rep(i, 0, n)
        if(depth1[i] > maxDepth)
            maxDepth = depth1[i], idx1 = i;
    
    depth1[idx1] = 0;
    dfs(idx1, -1, depth1, dfs);

    int idx2 = maxDepth = -1;
    rep(i, 0, n)
        if(depth1[i] > maxDepth)
            maxDepth = depth1[i], idx2 = i;
    
    vi depth2(n);
    dfs(idx2, -1, depth2, dfs);

    rep(i, 0, n)
        cout << max(depth1[i], depth2[i]) << ' ';
    cout << '\n';

    return 0;
}