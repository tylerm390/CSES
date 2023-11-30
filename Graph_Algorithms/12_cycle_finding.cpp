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
const ll inf = 2e18;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m; cin >> n >> m;
 
    vector<edge> edges(m);
    for(auto &[u, v, w]: edges) {
        cin >> u >> v >> w; u--, v--;
    }
 
    vector<ll> dist(n);
    vi par(n, -1);
    int last = -1;
    rep(i, 0, n) {
        for(auto [u, v, w]: edges) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
                if(i == n-1) last = v;
            }
        }
    }
 
    if(last == -1) {
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";
 
    rep(i, 0, n) last = par[last];
 
    vi cycle = {last};
    int cur = last;
    do {
        cur = par[cur];
        cycle.push_back(cur);
    } while(cur != last);
 
    reverse(all(cycle));
 
    for(int i: cycle)
        cout << i+1 << ' ';
    cout << '\n';
 
    return 0;
}