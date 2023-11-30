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
    vi inDeg(n);

    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        inDeg[v]++;
    }

    queue<int> q;
    rep(i, 0, n)
        if(inDeg[i] == 0)
            q.push(i);

    vi topSort;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        topSort.push_back(cur);
        for(int nxt: adj[cur])
            if(--inDeg[nxt] == 0)
                q.push(nxt);
    }

    if(sz(topSort) != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int i: topSort)
        cout << i + 1 << ' ';
    cout << '\n';

    return 0;
}