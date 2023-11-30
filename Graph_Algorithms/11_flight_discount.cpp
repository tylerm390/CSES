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
 
using pli = pair<ll, int>;
using vli = vector<pli>;
 
const ll inf = 1e15;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m; cin >> n >> m;
    vvii adj(2*n);
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[u+n].emplace_back(v+n, w);
        adj[u].emplace_back(v+n, w >> 1);
    }
 
    priority_queue<pli, vli, greater<pli>> pq;
    vector<ll> dists(2*n, inf);
 
    pq.emplace(0, 0);
    dists[0] = 0;
 
    while(!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
 
        if(d > dists[cur]) continue;
 
        for(auto[nxt, wt]: adj[cur]) {
            ll nxtD = d + wt;
            if(nxtD >= dists[nxt]) continue;
            dists[nxt] = nxtD;
            pq.emplace(nxtD, nxt);
        }
    }
 
    cout << min(dists[n-1], dists[2*n-1]) << '\n';
 
    return 0;
}