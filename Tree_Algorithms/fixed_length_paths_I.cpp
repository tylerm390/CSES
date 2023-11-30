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

    int n, k; cin >> n >> k;
    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> is_blocked(n);

    vi subtree_size(n);
    auto get_subtree_sizes = [&](int cur, int prv, auto &dfs) -> int {
        subtree_size[cur] = 1;
        for(int nxt: adj[cur]) if(nxt != prv && !is_blocked[nxt])
            subtree_size[cur] += dfs(nxt, cur, dfs);
        return subtree_size[cur];
    };

    auto get_centroid = [&](int cur, int prv, int nodes, auto &dfs) -> int {
        for(int nxt: adj[cur]) if(nxt != prv && !is_blocked[nxt])
            if(subtree_size[nxt] > nodes/2)
                return dfs(nxt, cur, nodes, dfs);
        return cur;
    };

    int ans = 0;

    auto centroid_decomp = [&](int cur, auto &dfs) -> vi {
        int nodes = get_subtree_sizes(cur, -1, get_subtree_sizes);
        int root = get_centroid(cur, -1, nodes, get_centroid);
        get_subtree_sizes(root, -1, get_subtree_sizes);
        is_blocked[root] = true;

        vi path_lengths(nodes+1);
        path_lengths[0] = 1;

        for(int nxt: adj[cur]) if(!is_blocked[nxt]) {
            vi child_ans = dfs(nxt, dfs);
            rep(i, 0, sz(child_ans)) {
                if(i+1 <= k/2)
                    ans += child_ans[i] * path_lengths[k - i - 1];
                path_lengths[i+1] += child_ans[i];
            }
        }

        return path_lengths;
    };

    centroid_decomp(0, centroid_decomp);

    cout << ans << '\n';

    return 0;
}