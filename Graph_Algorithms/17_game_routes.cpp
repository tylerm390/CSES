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

const int mod = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vvi adj(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }

    vi dp(n, -1);
    auto solve = [&](int cur, auto &solve) {
        if(cur == n-1) return 1;
        
        int &res = dp[cur];
        if(res != -1) return res;

        res = 0;
        for(int nxt: adj[cur])
            res = (res + solve(nxt, solve)) % mod;
        
        return res;
    };

    cout << solve(0, solve) << '\n';

    return 0;
}