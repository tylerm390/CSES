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
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi color(n, 0);
    auto dfs = [&](int cur, int curColor, auto &dfs) -> bool {
        if(color[cur] != 0) return color[cur] == curColor;
        color[cur] = curColor;
        for(int nxt: adj[cur])
            if(!dfs(nxt, 3 - curColor, dfs))
                return false;
        return true;
    };

    rep(i, 0, n) {
        if(color[i] == 0 && !dfs(i, 1, dfs)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    rep(i, 0, n)
        cout << color[i] << ' ';
    cout << '\n';

    return 0;
}