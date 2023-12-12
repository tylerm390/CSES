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
 
const ll inf = 1e15;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m, q;
    cin >> n >> m >> q;
 
    vector<vector<ll>> dists(n, vector<ll>(n, inf));
    rep(i, 0, n) dists[i][i] = 0;
    
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        dists[u][v] = min(dists[u][v], (ll)w);
        dists[v][u] = min(dists[v][u], (ll)w);
    }
 
    rep(k, 0, n)
        rep(i, 0, n)
            rep(j, 0, n)
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
    
    while(q--) {
        int u, v; cin >> u >> v;
        u--, v--;
        if(dists[u][v] == inf)
            cout << -1 << '\n';
        else
            cout << dists[u][v] << '\n';
    }
 
    return 0;
}