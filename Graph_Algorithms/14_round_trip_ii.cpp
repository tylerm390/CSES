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
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }

    stack<int> s;
    vi seen(n);
    vi cycle; int last = -1;
    auto dfs = [&](int cur, auto &dfs) -> bool {
        if(seen[cur] == 2) return false;
        if(seen[cur] == 1) {
            last = cur;
            cycle.push_back(cur);
            return true;
        }

        seen[cur] = 1;
        s.push(cur);
        for(int nxt: adj[cur])
            if(dfs(nxt, dfs)) break;
        
        seen[cur] = 2;
        
        if(last != -1) {
            if(last >= 0) cycle.push_back(cur);
            if(last == cur) last = -2;
            return true;
        }

        return false;
    };

    rep(i, 0, n)
        if(dfs(i, dfs)) break;
    
    if(sz(cycle) == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(all(cycle));
    cout << sz(cycle) << '\n';
    for(int u: cycle) cout << u + 1 << ' ';
    cout << '\n';

    return 0;
}