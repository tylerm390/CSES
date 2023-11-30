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
 
using edge = tuple<int, int, int>;
 
const ll inf = 1e15;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m; cin >> n >> m;
    vector<edge> edges;
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        edges.emplace_back(u, v, -w);
    }
 
    vector<ll> dists(n, inf);
    dists[0] = 0;
 
    rep(iter, 0, n) {
        for(auto [cur, nxt, wt]: edges) {
            if(abs(dists[cur]) == inf) continue;
            ll nxtDist = dists[cur] + wt;
            if(nxtDist < dists[nxt])
                dists[nxt] = (iter == n-1 ? -inf : nxtDist);
        }
    }
 
    rep(iter, 0, n-1)
        for(auto [cur, nxt, wt]: edges)
            if(dists[cur] == -inf)
                dists[nxt] = -inf;
 
    if(dists[n-1] == -inf)
        cout << -1 << '\n';
    else
        cout << -dists[n-1] << '\n';
 
    return 0;
}