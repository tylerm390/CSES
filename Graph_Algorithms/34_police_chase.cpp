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
 
struct FFA {
    int n;
    vector<vector<ll>> adj;
    FFA(int n): n(n), adj(n, vector<ll>(n)) {}
    void addEdge(int u, int v, int c) { adj[u][v] += c; }
    vector<bool> seen;
    ll dfs(int cur, int t, ll thresh, ll flow = 1e15) {
        if(cur == t) return flow;
        rep(nxt, 0, n) {
            if(seen[nxt] || adj[cur][nxt] < thresh) continue;
            seen[nxt] = true;
            if(ll f = dfs(nxt, t, thresh, min(flow, adj[cur][nxt]))) {
                adj[cur][nxt] -= f;
                adj[nxt][cur] += f;
                return f;
            }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0, f;
        rep(i, 0, 31)
            while(seen = vector<bool>(n), seen[s] = true, 
                    (f = dfs(s, t, 1<<(30-i)))) 
                flow += f;
        return flow;
    }
    bool leftOfMinCut(int x) { return !seen[x]; }
};
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m; cin >> n >> m;
    FFA flow(n);
    vii edges;
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        flow.addEdge(u, v, 1);
        flow.addEdge(v, u, 1);
        edges.emplace_back(u, v);
    }
 
    cout << flow.calc(0, n-1) << '\n';
    for(auto [u, v]: edges)
        if(flow.leftOfMinCut(u) != flow.leftOfMinCut(v))
            cout << u+1 << ' ' << v+1 << '\n';
 
    return 0;
}