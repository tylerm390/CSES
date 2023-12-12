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

    vector<ll> depth(n), subtreeSize(n);
    auto dfs = [&](int cur, int prv, auto &dfs) -> void {
        subtreeSize[cur] = 1;
        for(int nxt: adj[cur]) if(nxt != prv) {
            depth[nxt] = depth[cur] + 1;
            dfs(nxt, cur, dfs);
            subtreeSize[cur] += subtreeSize[nxt];
        }
    };
    dfs(0, -1, dfs);

    vector<ll> ans(n);
    ans[0] = accumulate(all(depth), 0LL);

    auto reroot = [&](int cur, int prv, auto &reroot) -> void {
        for(int nxt: adj[cur]) if(nxt != prv) {
            ans[nxt] = ans[cur] + n - 2 * subtreeSize[nxt];
            reroot(nxt, cur, reroot); 
        }
    };
    reroot(0, -1, reroot);

    for(ll i: ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}