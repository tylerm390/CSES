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
    vvi fwdAdj(n), revAdj(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        fwdAdj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    auto dfs = [&](int cur, vector<bool> &seen, vvi &adj, auto &dfs) -> void {
        for(int nxt: adj[cur]) {
            if(seen[nxt]) continue;
            seen[nxt] = true;
            dfs(nxt, seen, adj, dfs);
        }
    };

    vector<bool> reachedFwd(n, false);
    reachedFwd[0] = true;
    dfs(0, reachedFwd, fwdAdj, dfs);

    vector<bool> reachedRev(n, false);
    reachedRev[0] = true;
    dfs(0, reachedRev, revAdj, dfs);

    pii res(-1, -1);
    rep(i, 0, n) {
        if(!reachedFwd[i]) {
            res = pii(0, i);
            break;
        }
        if(!reachedRev[i]) {
            res = pii(i, 0);
            break;
        }
    }

    if(res == pii(-1, -1)) {
        cout << "YES\n";
    }    
    else {
        cout << "NO\n";
        cout << res.first+1 << " " << res.second+1 << '\n';
    }

    return 0;
}