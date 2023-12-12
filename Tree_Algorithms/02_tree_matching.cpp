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

    vvi dp(n, vi(2, -1));

    auto solve = [&](int cur, int prv, int matched, auto &solve) -> int {
        int &res = dp[cur][matched];
        if(res != -1) return res;

        int m = sz(adj[cur]);
        vi dontMatch(m);
        rep(i, 0, m) if(adj[cur][i] != prv)
            dontMatch[i] = solve(adj[cur][i], cur, 0, solve);
        
        int tot = res = accumulate(all(dontMatch), 0);
        if(matched) return res;

        rep(i, 0, m) if(adj[cur][i] != prv) {
            int match = tot - dontMatch[i] + solve(adj[cur][i], cur, 1, solve) + 1;
            res = max(res, match);
        }

        return res;
    };

    cout << solve(0, -1, 0, solve) << '\n';

    return 0;
}