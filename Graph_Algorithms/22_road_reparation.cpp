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

struct DSU {
    vi e;
    DSU(int n): e(n, -1) {}
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(e[x] < e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

using edge = tuple<int, int, int>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<edge> edges(m);
    for(auto &[w, u, v]: edges)
        cin >> u >> v >> w, u--, v--;
    
    sort(all(edges));

    DSU dsu(n);
    ll tot = 0, joins = 0;
    for(auto [w, u, v]: edges)
        if(dsu.join(u, v))
            tot += w, joins++;
    
    if(joins != n-1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << tot << '\n';

    return 0;
}