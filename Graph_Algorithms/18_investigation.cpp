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
using tiii = tuple<int, int, int>;

using state = pair<ll, int>;

const ll inf = 1e18;
const int mod = 1e9 + 7;

vector<ll> dijkstras(vvii &adj, int s) {
    priority_queue<state, vector<state>, greater<state>> pq;
    vector<ll> dists(sz(adj), inf);
    dists[s] = 0;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if(dists[cur] < d) continue;
        for(auto [nxt, wt]: adj[cur]) {
            ll nxtD = d + wt;
            if(dists[nxt] <= nxtD) continue;
            dists[nxt] = nxtD;
            pq.emplace(nxtD, nxt);
        }
    }

    return dists;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vvii fwdAdj(n), revAdj(n);
    vector<tiii> edges;
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        fwdAdj[u].emplace_back(v, w);
        revAdj[v].emplace_back(u, w);
        edges.emplace_back(u, v, w);
    }

    auto fwdDists = dijkstras(fwdAdj, 0);
    auto revDists = dijkstras(revAdj, n-1);

    vvi dag(n);
    for(auto [u, v, w]: edges)
        if(fwdDists[u] + revDists[v] + w == fwdDists[n-1])
            dag[u].push_back(v);
    
    vector<tiii> dp(n, {-1, -1, -1});
    auto solve = [&](int cur, auto &solve) -> tiii {
        if(sz(dag[cur]) == 0) return {1, 0, 0};
        auto &res = dp[cur];
        if(res != tiii{-1, -1, -1}) return res;

        int cnt = 0, maxFlights = 0, minFlights = 1e9;
        for(int nxt: dag[cur]) {
            auto [a, b, c] = solve(nxt, solve);
            cnt = (cnt + a) % mod;
            maxFlights = max(maxFlights, b + 1);
            minFlights = min(minFlights, c + 1);
        }

        return res = tie(cnt, maxFlights, minFlights);
    };

    auto [cnt, maxFlights, minFlights] = solve(0, solve);

    cout << fwdDists[n-1] << ' ' << cnt << ' ' << minFlights << ' ' << maxFlights << '\n';

    return 0;
}