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
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi subtree_size(n);
    auto get_subtree_sizes = [&](int cur, int prv, auto &dfs) -> void {
        subtree_size[cur] = 1;
        for(int nxt: adj[cur]) if(nxt != prv) {
            dfs(nxt, cur, dfs);
            subtree_size[cur] += subtree_size[nxt];
        }
    };

    auto get_centroid = [&](int cur, int prv, auto &dfs) -> int {
        for(int nxt: adj[cur]) if(nxt != prv)
            if(subtree_size[nxt] > n/2)
                return dfs(nxt, cur, dfs);
        return cur;
    };

    get_subtree_sizes(0, -1, get_subtree_sizes);
    cout << get_centroid(0, -1, get_centroid) + 1 << '\n';

    return 0;
}