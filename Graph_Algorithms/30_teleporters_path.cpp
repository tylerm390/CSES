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
using vvii = vector<vii>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vvii adj(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].emplace_back(v, i);
    }

    deque<int> s = {0};
    vi idxs(n), deg(n), seen(m);
    deg[0] = 1;
    deg[n-1] = -1;
    vi euler;
    while(!s.empty()) {
        auto cur = s.back();
        if(idxs[cur] == sz(adj[cur])) {
            euler.push_back(cur);
            s.pop_back();
            continue;
        }
        auto [nxt, id] = adj[cur][idxs[cur]++];
        if(seen[id]) continue;
        seen[id] = 1;
        deg[cur]--, deg[nxt]++;
        s.push_back(nxt);
    }

    if(sz(euler) != m+1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    rep(i, 0, n) {
        if(deg[i] != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    reverse(all(euler));
    for(int i: euler)
        cout << i+1 << ' ';
    cout << '\n';

    return 0;
}