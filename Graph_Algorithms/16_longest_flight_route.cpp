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
 
const int inf = 1e9;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m; cin >> n >> m;
    vvi adj(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }
 
    vi dp(n, -inf), bb(n, -1);
    
    auto solve = [&](int cur, auto &solve) -> int {
        if(cur == n-1) return 1;
        
        int &res = dp[cur];
        if(res != -inf) return res;
 
        res = -1;
        for(int nxt: adj[cur]) {
            int nxtRes = solve(nxt, solve);
            if(nxtRes != -1 && nxtRes + 1 > res)
                res = nxtRes + 1, bb[cur] = nxt;
        }
 
        return res;
    };
 
    int res = solve(0, solve);
 
    if(res == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    cout << res << '\n';
 
    vi path = {0};
    int cur = 0;
    while(cur != n-1) {
        cur = bb[cur];
        path.push_back(cur);
    }
 
    for(int i: path)
        cout << i + 1 << ' ';
    cout << '\n';
 
    return 0;
}