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

using state = pair<ll, int>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, k; cin >> n >> m >> k;
    vvii adj(n);
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].emplace_back(v, w);
    }

    priority_queue<state, vector<state>, greater<state>> pq;
    vector<priority_queue<ll>> dists(n);

    pq.emplace(0, 0);
    dists[0].push(0);

    while(!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if(d > dists[cur].top()) continue;
        for(auto [nxt, wt]: adj[cur]) {
            ll nxtD = d + wt;
            if(sz(dists[nxt]) < k) {
                dists[nxt].push(nxtD);
                pq.emplace(nxtD, nxt);
            }
            else if(nxtD < dists[nxt].top()) {
                dists[nxt].pop();
                dists[nxt].push(nxtD);
                pq.emplace(nxtD, nxt);
            }
        }
    }

    vector<ll> res;
    while(sz(dists[n-1])) {
        res.push_back(dists[n-1].top());
        dists[n-1].pop();
    }
    reverse(all(res));

    for(ll r: res) cout << r << ' ';
    cout << '\n';

    return 0;
}