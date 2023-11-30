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
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi dist(n, inf);
    vi par(n, -1);
    queue<int> q;

    dist[0] = 1;
    q.push(0);

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int nxt: adj[cur]) {
            if(dist[nxt] != inf) continue;
            dist[nxt] = dist[cur] + 1;
            par[nxt] = cur;
            q.push(nxt);
        }
    }

    if(dist[n-1] == inf) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dist[n-1] << '\n';

    vi path;
    int cur = n-1;
    while(cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }

    reverse(all(path));
    for(int pi: path)
        cout << pi + 1 << ' ';
    cout << '\n';

    return 0;
}